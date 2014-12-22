%{
#include <iostream>
#include <string>
#include <vector>
#include <stack>

/**
 * Yacc needs this declaration for error handling.
 */
void yyerror(const char *str);

/**
 * This function is needed by bison. It tell it to continue streaming another 
 * file after the first one is done, if the return is different than one.
 */
int yywrap();

/**
 *
 */
std::stack<std::string> g_classes;

%}

// Provides better error checking messages in yyerror function.
%error-verbose

// yacc fundamentally works by asking lex to get the next token, which it returns as
// an object of type "yystype".  But
// the next token could be of an arbitrary data type, so you can define a C union to
// hold each of the types of tokens that lex could return, and yacc will typedef
// "yystype" as the union instead of its default (int):

%union {
	int ival;
	char sval[1024];
}

// and then you just associate each of the defined token types with one of
// the union fields and we're happy:
%token <ival> CMD_TOKEN_LITERAL_INTEGER
%token <ival> CMD_TOKEN_LITERAL_SIGNAL_INTEGER
%token <sval> CMD_TOKEN_LITERAL_STRING
%token <sval> CMD_TOKEN_LITERAL_STRING_SPACES
%token <sval> CMD_TOKEN_LITERAL_PASSWORD

%token <sval> CMD_TOKEN_OPERATOR_GREATER
%token <sval> CMD_TOKEN_OPERATOR_LESS
%token <sval> CMD_TOKEN_OPERATOR_EQUAL

%token <sval> CMD_TOKEN_AUTH
%token <sval> CMD_TOKEN_GET
%token <sval> CMD_TOKEN_SET
%token <sval> CMD_TOKEN_QUERY
%token <sval> CMD_TOKEN_NULL

%token <sval> CMD_TOKEN_ANYTHING

%token CLASS
%token PUBLIC
%token COLON

%type <ival> number
%type <sval> string
%type <sval> value
%type <sval> table
%type <sval> key
%type <sval> column
%type <sval> username
%type <sval> password
%type <ival> version

%type <sval> operator_numeric
%type <sval> operator_string


%start commands

%%

trash
	:
	;
	
class
	: class_begin class_body class_end
	;

class_begin
	: CLASS trash identifier SEMICOLON {}
	: CLASS trash identifier trash BRACER_OPEN {
		g_classes.push( $3 );
	}
	;

class_body
	: trash PUBLIC COLON

class_end
	: BRACER_CLOSE
	;

password
	: CMD_TOKEN_LITERAL_STRING 
	| CMD_TOKEN_LITERAL_PASSWORD
	;

number
	: CMD_TOKEN_LITERAL_SIGNAL_INTEGER
	| CMD_TOKEN_LITERAL_INTEGER
	;

string
	: CMD_TOKEN_LITERAL_STRING_SPACES
	| CMD_TOKEN_LITERAL_STRING
	;
	
value
	: number  {
		snprintf( $$, sizeof($$), "%d", $1 );
	}
	| string {
		strcpy( $$, $1 );
	}
	;

table
	: CMD_TOKEN_LITERAL_STRING
	;
	
key
	: CMD_TOKEN_LITERAL_STRING
	;
	
column
	: CMD_TOKEN_LITERAL_STRING
	;
	
version
	: CMD_TOKEN_LITERAL_INTEGER
	;

commands
	: command {
		YYACCEPT;
	}
	| error {
		sprintf( gp_return_buffer, "%s", g_last_error_message );
	}
	;

command
	: command_auth
	| command_get
	| command_set
	| command_query
	;

command_auth
	: CMD_TOKEN_AUTH CMD_TOKEN_TAB username CMD_TOKEN_TAB password {
		char * l_username = $3;
		char * l_password = $5;
		
		// Assert that the username is ok!
		if ( strcmp( l_username, gp_params->username ) != 0 )
		{
			g_error_code = ERR_AUTHENTICATION_FAILED;	
			
			char l_message[1024];
			snprintf( l_message, sizeof(l_message), "Username not found: %s", l_username );
			yyerror( l_message );
			YYABORT;
		}
		// Assert that the password is ok!
		if ( strcmp( l_password, gp_params->password ) != 0 )
		{
			g_error_code = ERR_AUTHENTICATION_FAILED;

			char l_message[1024];
			snprintf( l_message, sizeof(l_message), "Password does not match: %s", l_password );
			yyerror( l_message );
			YYABORT;
		}
		
		// If we got here, then the user is ok to login!
		// Now we register his login in the system.
		
		// Creating the structure to hold the client's login
		PtrClientAccess lp_client_access_new = ClientAccess_new();
		// Setting the parameters
		lp_client_access_new->authenticated = 1;
		lp_client_access_new->socket_conn = g_socket;
		strcpy( lp_client_access_new->username, l_username );
		strcpy( lp_client_access_new->password, l_password );
		// And finally inserting it.
		tsearch( (void*) lp_client_access_new, (void**) &gp_sys_table_client_access, ClientAccess_search_key );

		sprintf( gp_return_buffer, "RESP_AUTH\n" );
		g_error_code = 0;
	}
	;
	
command_get
	: CMD_TOKEN_GET CMD_TOKEN_TAB table CMD_TOKEN_TAB key {
		// Can't execute this command if the client is not authenticated yet.
		if( !check_current_connection_authenticated() )
			YYABORT;
		
		// Creating aliases to better undentify the values.
		char * l_table_name = $3;
		char * l_key_name = $5;
		
		PtrEntry lp_table_column = NULL;
		PtrEntry lp_table_record = NULL;
		
		if( !get_table_from_hash( l_table_name, &lp_table_column, &lp_table_record ) )
			YYABORT;
		
		//PtrPtrColumn lpp_table_column_tree = (PtrPtrColumn) &(lp_table_column->data);
		PtrPtrRecord lpp_table_record_tree = (PtrPtrRecord) &(lp_table_record->data);
		
		// Creates a structure to query the table record
		Record l_table_record_search;
		strcpy( l_table_record_search.key, l_key_name );
		// Retrieves the table record
		PtrPtrRecord lpp_table_record = (PtrPtrRecord) tfind( (void*) &l_table_record_search, 
			(void**) lpp_table_record_tree, Record_search_key );
		
		if ( lpp_table_record == NULL )
		{
			g_error_code = ERR_KEY_NOT_FOUND;

			char l_message[1024];
			snprintf( l_message, sizeof(l_message), "Register not found: %s %s", l_table_name, l_key_name );
			yyerror( l_message );
			YYABORT;
		}
		
		sprintf( gp_return_buffer, "RESP_GET %lu %s\n", (*lpp_table_record)->version, (*lpp_table_record)->value );
		g_error_code = 0;
	}
	;
	
command_set
	: CMD_TOKEN_SET CMD_TOKEN_TAB table CMD_TOKEN_TAB key CMD_TOKEN_TAB version CMD_TOKEN_TAB columns_values {
		// Can't execute this command if the client is not authenticated yet.
		if( !check_current_connection_authenticated() )
			YYABORT;
			
		// Creating aliases to better indentify the values.
		char * l_table_name = $3;
		char * l_key = $5;
		ulong l_version = $7;
		
		PtrEntry lp_table_column = NULL;
		PtrEntry lp_table_record = NULL;
		// Checks if the table exists and retrieve the column and record Entry datatype.
		if( !get_table_from_hash( l_table_name, &lp_table_column, &lp_table_record ) )
			YYABORT;
		
		// The address of the data part of the Entry is the address of the first node
		PtrPtrColumn lpp_table_column_tree = (PtrPtrColumn) &(lp_table_column->data);
		
#ifdef DEBUG
		if( l_column_index == 0 )
			twalk( (*lpp_table_column_tree), Column_callback_print_columns );
#endif // DEBUG
	
		PtrPtrColumn lpp_table_column = NULL;
		// Used to retrieve the data to the current column (from the database and from the ColumnValue structure).
		int l_column_index = -1;
		// Counts the number of columns for this table.
		int l_column_count = 0;
		// Test if the columns received match with the ones described in the config file.
		while ( 1 )
		{	
			//Increase the index, to retrieve the next column.
			l_column_index++;
			
			// Retrieves the metada data for this column.
			Column l_table_column_search;
			l_table_column_search.id = l_column_index;
			lpp_table_column = (PtrPtrColumn) tfind( (void*) &l_table_column_search, 
				(void**) lpp_table_column_tree, Column_search_id );
				
			// This is our out condition of the do-while loop	
			if( lpp_table_column == NULL )
				break;
			
			// We found a column!
			l_column_count++;
							
			// Asserts that the amount of columns we received during the parsing
			// is not SHORTER than what was declared in the config file.
			if( l_column_index > g_column_value_count )
			{
				g_error_code = ERR_INVALID_PARAM;

				char l_message[1024];
				snprintf( l_message, sizeof(l_message), 
					"In table %s: received more columns (%d) than the table %s has declared", l_table_name, g_column_value_count, l_table_name );
				yyerror( l_message );
				YYABORT;
			}
		
			// Retrieves and creates an alias to the "l_column_index"th ColumnValue parsed.
			char * l_column = g_column_value_array[l_column_index].column;
			char * l_value  = g_column_value_array[l_column_index].value;
			
			// Creating an alias to the current column
			PtrColumn lp_table_column = *(lpp_table_column);
			
			// Check if the current column matches the name of the column informed.
			// The columns must be informed in the same order as they were declared
			// in the configuration file.
			if( strcmp( lp_table_column->name, l_column ) != 0 )
			{
				g_error_code = ERR_INVALID_PARAM;

				char l_message[1024];
				snprintf( l_message, sizeof(l_message), 
					"In table %s the column received (%s) does not match the column expected (%s).", 
					l_table_name, l_column, lp_table_column->name );
				yyerror( l_message );
				YYABORT;
			}
			
			// Cheking if the type of the value received is the same as the one
			// expected by the column.					
			if( strcmp( lp_table_column->type, COLUMN_TYPE_INT ) == 0 )
			{
				// Verifies if the value was purelly an integer.
				char * l_not_an_integer = NULL;
				int l_value_int = strtol( l_value, &l_not_an_integer, 10 );
				// If the value was not fully converted to a int, raise an error.
				if ( (*l_not_an_integer) )
				{
					g_error_code = ERR_INVALID_PARAM;

					char l_message[1024];
					snprintf( l_message, sizeof(l_message), 
						"Expected type %s for column %s in table %s, but got value %s", 
						COLUMN_TYPE_INT, l_column, l_table_name, l_value );
					yyerror( l_message );
					YYABORT;
				}
				// Converts back to integer, just to make sure we are not storing the + simbol.
				snprintf( l_value, sizeof(l_value), "%d", l_value_int );
			}
			// We presume the value is a string if none of these tests pass (int, float, ... )	
			else
			{
				// Raise an error if the value given is bigger than the max size of the column
				if( strlen( l_value ) > lp_table_column->size )
				{
					g_error_code = ERR_INVALID_PARAM;

					char l_message[1024];
					snprintf( l_message, sizeof(l_message), 
						"The string given (%s) is bigger than the maximun capacity (%d) of the column %s for table %s",
						l_value, lp_table_column->size, lp_table_column->name, l_table_name );
					yyerror( l_message );
					YYABORT;
				}
			}						
		}
				
		// Asserts that the amount of columns we received during the parsing
		// is not LONGER than what was declared in the config file.
		if( l_column_count != g_column_value_count )
		{
			g_error_code = ERR_INVALID_PARAM;

			char l_message[1024];
			snprintf( l_message, sizeof(l_message), 
				"Received more columns (%d) than the table %s has declared (%d)", 
				g_column_value_count, l_table_name, l_column_count );
			yyerror( l_message );
			YYABORT;
		}		
		
		// Now that we asserted that the columns and values are OK, we then check
		// if the record already exists. If it does not, them we create a new one.
		
		// We start by formatting the value part.
		char l_value_formmated[MAX_VALUE_LEN];		
		int i;
		for( i = 0; i < l_column_count; i++ )
		{
			// Creating aliases
			char * l_column = g_column_value_array[i].column;
			char * l_value  = g_column_value_array[i].value;
			
			char l_column_value[MAX_VALUE_LEN];
			// When it is the last register, we don't add the comma.
			snprintf( l_column_value, sizeof(l_column_value), "%s %s%s", 
				l_column, l_value, ( (i+1) == l_column_count ) ? "" : "," );
		
			// c doesn't have a good string joinning function, so improvise.
			// when it is the first record, we copy it, instead of concatenating.
			if( i == 0 ) {
				strncpy( l_value_formmated, l_column_value, sizeof(l_value_formmated) );
			} else {
				strncat( l_value_formmated, l_column_value, sizeof(l_value_formmated) );
			}
		}
		
		// The address of the data part of the Entry is the address of the first node
		PtrPtrRecord lpp_table_record_tree = (PtrPtrRecord) &(lp_table_record->data);
		
		// Retrieves the table record data.
		Record l_table_record_search;
		strcpy( l_table_record_search.key, l_key );
		PtrPtrRecord lpp_table_record = (PtrPtrRecord) tfind( (void*) &l_table_record_search, 
			(void**) lpp_table_record_tree, Record_search_key );
		
		// if the record already exists, we just update it's value part
		if( lpp_table_record != NULL )
		{
			PtrRecord lp_table_record = (*lpp_table_record);
			
			// There will be a transaction error if we are using threads AND if the version 
			// received is different from the version of the record.
			if( l_version != 0 && l_version != lp_table_record->version )
			{
				g_error_code = ERR_TRANSACTION_ABORT;

				char l_message[1024];
				snprintf( l_message, sizeof(l_message), "Transaction version (%lu) differs from the database (%lu)", 
					l_version, lp_table_record->version );
				yyerror( l_message );
				YYABORT;
			}
			
			strncpy( lp_table_record->value, l_value_formmated, sizeof( lp_table_record->value) );
			lp_table_record->version++;
		}
		// if it doesn't, then we need to create it.
		else
		{
			PtrRecord lp_table_record_new = Record_new( l_key, l_value_formmated );
			tsearch( (void*) lp_table_record_new, (void**) lpp_table_record_tree, Record_search_key );
		}
		
		sprintf( gp_return_buffer, "RESP_SET %s\n", lpp_table_record ? "UPDATE" : "INSERT" );
		g_error_code = 0;	
	}
	| CMD_TOKEN_SET CMD_TOKEN_TAB table CMD_TOKEN_TAB key CMD_TOKEN_TAB CMD_TOKEN_NULL {
		// Can't execute this command if the client is not authenticated yet.
		if( !check_current_connection_authenticated() )
			YYABORT;
		
		// Creating aliases to better indentify the parsed values.
		char * l_table_name = $3;
		char * l_key = $5;
		
		PtrEntry lp_table_column = NULL;
		PtrEntry lp_table_record = NULL;
		// Checks if the table exists and retrieve the column and record Entry datatype.
		if( !get_table_from_hash( l_table_name, &lp_table_column, &lp_table_record ) )
			YYABORT;
		
		// The address of the data part of the Entry is the address of the first node
		PtrPtrRecord lpp_table_record_tree = (PtrPtrRecord) &(lp_table_record->data);
		// Retrieves the table record data.
		Record l_table_record_search;
		strcpy( l_table_record_search.key, l_key );
		PtrPtrRecord lpp_table_record = (PtrPtrRecord) tfind( (void*) &l_table_record_search, 
			(void**) lpp_table_record_tree, Record_search_key );
		
		// If the record doesn't exist, we raise an exception, 
		// 'cause we can't delete what doesn't exist.	
		if( lpp_table_record == NULL )
		{
			g_error_code = ERR_KEY_NOT_FOUND;

			char l_message[1024];
			snprintf( l_message, sizeof(l_message), "Register not found: %s %s", l_table_name, l_key );
			yyerror( l_message );
			YYABORT;
		}
		
		// If it exists, then we just delete it.		
		tdelete( (void*) &l_table_record_search, (void**) lpp_table_record_tree, Record_search_key );
		
		sprintf( gp_return_buffer, "RESP_SET DELETE\n" );
		g_error_code = 0;
	}
	;

columns_values
	: column_value_comma
	;

column_value_comma
	: column_value_comma CMD_TOKEN_COMMA column_value 
	| column_value 
	;
	
column_value
	: column value {
		g_column_value_count++;
		
		if( g_column_value_count > MAX_COLUMNS_PER_TABLE )
		{
			char l_message[1024];
			snprintf( l_message, sizeof(l_message), "Error: Maximun number of columns is %d", MAX_COLUMNS_PER_TABLE );
			yyerror( l_message );
			YYABORT;
		}
		
		int l_index = g_column_value_count - 1;
		
		strncpy( g_column_value_array[l_index].column, $1, sizeof(g_column_value_array[l_index].column) );
		strncpy( g_column_value_array[l_index].value , $2, sizeof(g_column_value_array[l_index].value ) );
	}
	;

command_query
	: CMD_TOKEN_QUERY CMD_TOKEN_TAB table CMD_TOKEN_TAB predicates {
		// Can't execute this command if the client is not authenticated yet.
		if( !check_current_connection_authenticated() )
			YYABORT;
		
		// This variable is used to flag an error, used by the callback methods.
		g_error_predicate = 0;
		// We also set a global variable to store the name of the table.
		char * l_table_name = $3;
		g_table_name = l_table_name;
		// Another global variable to store the maximun number of results
		g_keys_found = 0;
		// And another one to globally write the resulting keys.
		char l_result_buffer[ (MAX_KEY_LEN+1) * MAX_RECORDS_PER_TABLE];
		snprintf( l_result_buffer, sizeof(l_result_buffer), "%s", "" );
		g_predicate_callback_result_buffer = l_result_buffer;
		
		// We use global variables, because we will need these variables inside the callback methods:
		// Predicate_callback_assert_predicates, Predicate_callback_query_foreach_record and Predicate_callback_query_foreach_predicate.
		gp_predicate_table_column = NULL;
		gp_predicate_table_record = NULL;
		// Set those two globals and retrieves the Entry in the hashtable.
		if( !get_table_from_hash( l_table_name, &gp_predicate_table_column, &gp_predicate_table_record ) )
			YYABORT;
		
		// Now, we assert that the columns exist and that it's values are of the correct type.
		twalk( gp_predicate_tree, Predicate_callback_assert_predicates );
		// If an error happened in the callback function, we abort the operation.
		if( g_error_predicate )
			YYABORT;
			
		PtrPtrRecord lpp_table_record_tree_node = (PtrPtrRecord) &(gp_predicate_table_record->data);
		
		PtrRecord lp_record = *lpp_table_record_tree_node;
		
		// Now that everything is asserted, we query records with the predicates.
		twalk( lp_record, Predicate_callback_query_foreach_record );

		// If an error happened in the callback function, we abort the operation.
		if( g_error_predicate )
			YYABORT;
		
		sprintf( gp_return_buffer, "RESP_QUERY %s\n", l_result_buffer );
		g_error_code = 0;
	}
	;
	
predicates
	: predicate_comma predicate
	;

predicate_comma
	: predicate_comma predicate CMD_TOKEN_COMMA
	|
	;
		
predicate
	: CMD_TOKEN_LITERAL_STRING operator_string string {		
		// Creating a new predicate
		PtrPredicate lp_predicate = Predicate_new( $1, $2, $3 );
		// And then inserting into our node list (which happens to be a tree).
		tsearch( (void*) lp_predicate, (void**) &gp_predicate_tree, Predicate_search );
	}
	| CMD_TOKEN_LITERAL_STRING operator_numeric number {		
		char l_value[33];
		snprintf( l_value, sizeof(l_value), "%d", $3 );
		
		// Creating a new predicate
		PtrPredicate lp_predicate = Predicate_new( $1, $2, l_value );
		// And then inserting into our node list (which happens to be a tree).
		tsearch( (void*) lp_predicate, (void**) &gp_predicate_tree, Predicate_search );
	}
	;

operator_numeric
	: CMD_TOKEN_OPERATOR_EQUAL
	| CMD_TOKEN_OPERATOR_GREATER
	| CMD_TOKEN_OPERATOR_LESS
	;

operator_string
	: CMD_TOKEN_OPERATOR_EQUAL
	;

%%

static void Predicate_callback_assert_predicates( const void * app_predicate, const VISIT a_which, const int a_depth )
{
	if( g_error_predicate )
		return;

	if( a_which != postorder && a_which != leaf )
		return;
	
	// Retrieves the predicate data	
	PtrPredicate lp_predicate = *((PtrPtrPredicate)app_predicate);

	// Searching for the column.
	PtrColumn lp_column = Column_search_by_name( g_table_name, lp_predicate->column );
		
	// if the column was not found, then we make shit hit the fan!
	if( lp_column == NULL )
	{
		g_error_code = ERR_INVALID_PARAM;
		g_error_predicate = g_error_code;

		char l_message[1024];
		snprintf( l_message, sizeof(l_message), 
			"Column (%s) is not part of table %s.", lp_predicate->column, g_table_name );
		yyerror( l_message );
		return;
	}
	
	// now we check if the value is valid for the present column.
	if( strcmp( lp_column->type, COLUMN_TYPE_INT ) == 0 )
	{
		// Verifies if the value was purelly an integer.
		char * l_not_an_integer = NULL;
		strtol( lp_predicate->value, &l_not_an_integer, 10 );
		// If the value was not fully converted to a int, raise an error.
		if ( (*l_not_an_integer) )
		{
			g_error_code = ERR_INVALID_PARAM;
			g_error_predicate = g_error_code;

			char l_message[1024];
			snprintf( l_message, sizeof(l_message), 
				"The value %s of the predicate with column %s from table %s is expected to have type %s", 
				lp_predicate->value, lp_predicate->column, g_table_name, COLUMN_TYPE_INT );
			yyerror( l_message );
			return;
		}
	}
}

static void Predicate_callback_query_foreach_record( const void * app_table_record, const VISIT a_which, const int a_depth )
{
	if( g_error_predicate )
		return;

	if( a_which != postorder && a_which != leaf )
		return;	
		
	// Retrieves the record from the table
	PtrRecord lp_table_record = *((PtrPtrRecord)app_table_record);
	
	// Creating a new query result.
	// ok = 1 = true, which means that all registers are good to return, until we prove otherwise. 
	QueryResult l_query_result;
	strncpy( l_query_result.key  , lp_table_record->key  , sizeof(l_query_result.key  ) );
	strncpy( l_query_result.value, lp_table_record->value, sizeof(l_query_result.value) );
	l_query_result.ok = 1;
	
	gp_query_result = &l_query_result;
	
	// Test the record against all the predicates.
	twalk( gp_predicate_tree, Predicate_callback_query_foreach_predicate );
	
	// If an exception occured, we get out.
	if( g_error_predicate )
		return;

	if( gp_query_result->ok ) {
		g_keys_found++;
		if( strlen(g_predicate_callback_result_buffer) != 0 ) {
			strncat( g_predicate_callback_result_buffer, " ", sizeof(g_predicate_callback_result_buffer) );
		}
		
		printf( "Concatenating key[%s]\n", gp_query_result->key );
		
		strcat( g_predicate_callback_result_buffer, gp_query_result->key );
	}
}

static void Predicate_callback_query_foreach_predicate( const void * app_predicate, const VISIT a_which, const int a_depth )
{
	// if the current record has already failed one of the other predicates, them we just ignore the others.
	if( !gp_query_result->ok )
		return;

	if( g_error_predicate )
		return;

	if( a_which != postorder && a_which != leaf )
		return;

	// Retrieves the predicate data
	PtrPredicate lp_predicate = *((PtrPtrPredicate)app_predicate);
	
	char l_query_result_value[MAX_VALUE_LEN];
	strncpy( l_query_result_value, gp_query_result->value, sizeof(l_query_result_value) );
	
	// This returns to us "column value ..." where "..." can be commas, columns and  values.
	char * l_column_value = strstr ( l_query_result_value, lp_predicate->column ); 
	// Skips to the column we are searching.
	strtok( l_column_value, " " );
	// And then extracts the value part.
	char * l_value = strtok( NULL, "," );
	// eliminates any whitespaces between the value and the comma
	//trimwhitespace( l_value );
	
	// Searching for the column.
	PtrColumn lp_column = Column_search_by_name( g_table_name, lp_predicate->column );
	
	// Do the correct test, based on the type of the column.
	if( strcmp( lp_column->type, COLUMN_TYPE_INT ) == 0 )
	{
		int l_value_int = atoi( l_value );
		int l_predicate_value_int = atoi( lp_predicate->value );
	
		if( strcmp( lp_predicate->operator, PREDICATE_OPERATOR_EQUAL ) == 0 ) {
			gp_query_result->ok = ( gp_query_result->ok ) & ( l_value_int == l_predicate_value_int );
		} else if( strcmp( lp_predicate->operator, PREDICATE_OPERATOR_GREATER ) == 0 ) {
			gp_query_result->ok = ( gp_query_result->ok ) & ( l_value_int > l_predicate_value_int );
		} else if( strcmp( lp_predicate->operator, PREDICATE_OPERATOR_SMALLER ) == 0 ) {
			gp_query_result->ok = ( gp_query_result->ok ) & ( l_value_int < l_predicate_value_int );
		} else {
			g_error_code = ERR_UNKNOWN;
			g_error_predicate = g_error_code;
			
			char l_message[1024];
			snprintf( l_message, sizeof(l_message), "Operator %s not recognized!", lp_predicate->operator );
			yyerror( l_message );
			return;
		}
	}
	// It is not an int, so it is a string.
	else
	{
		if( strcmp( lp_predicate->operator, PREDICATE_OPERATOR_EQUAL ) == 0 ) {
			gp_query_result->ok = ( gp_query_result->ok ) & ( strcmp( l_value, lp_predicate->value ) == 0 );
		} else {
			g_error_code = ERR_UNKNOWN;
			g_error_predicate = g_error_code;
			
			char l_message[1024];
			snprintf( l_message, sizeof(l_message), "Operator %s not recognized!", lp_predicate->operator );
			yyerror( l_message );
			return;
		}
	}
}

static int check_current_connection_authenticated()
{
	// Creating the structure to search for the current connection.
	ClientAccess l_client_access_search;
	// Sets the key for the search
	l_client_access_search.socket_conn = g_socket;
	// Performs the query in the records.
	PtrPtrClientAccess lpp_client_access_found = (PtrPtrClientAccess) tfind( (void*) &l_client_access_search, 
		(void**) &gp_sys_table_client_access, ClientAccess_search_key );
	
	if( lpp_client_access_found == NULL )
	{
		g_error_code = ERR_NOT_AUTHENTICATED;

		char l_message[1024];
		snprintf( l_message, sizeof(l_message), "Client %d not authenticated yet!", g_socket );
		yyerror( l_message );
		
		return 0;
	}
	
	return 1;
}

static int get_table_from_hash( char * a_table_name, PtrPtrEntry app_table_column, PtrPtrEntry app_table_record )
{
	// Creating a searching structure, to find the given table name.
	Entry l_table_search;
	l_table_search.key = a_table_name;
	// This key should be able to retrive boths table from the Hashtables column and record.
	hsearch_r( l_table_search, FIND, app_table_column, gp_sys_table_column );
	hsearch_r( l_table_search, FIND, app_table_record, gp_sys_table_record );

	if ( *(app_table_column) == NULL || *(app_table_record) == NULL )
	{
		g_error_code = ERR_TABLE_NOT_FOUND;

		char l_message[1024];
		snprintf( l_message, sizeof(l_message),"Table not found: %s\n", a_table_name );
		yyerror( l_message );
		return 0;
	}
	
	return 1;
}

void yyerror(const char *str)
{
	logger( "ERROR %d %s\n", g_error_code, str );
	sprintf( gp_return_buffer, "ERROR %d %s\n", g_error_code, str );
	sprintf( g_last_error_message, "ERROR %d %s\n", g_error_code, str );
}

int commandwrap()
{
        return 1;
}

int command_parse( FILE* a_stream, struct config_params * ap_params, int a_socket, char * ap_return_buffer )
{
	gp_params = ap_params;
	
	g_socket = a_socket;
	
	gp_return_buffer = ap_return_buffer;

	g_column_value_count = 0;

	gp_predicate_tree = NULL;
	
	g_error_code = ERR_INVALID_PARAM;
	
	commandrestart( a_stream );

	int l_return = commandparse();
	
	if( gp_predicate_tree )
		tdestroy( gp_predicate_tree, free );
	
	printf( "%s", gp_return_buffer );
	
	return l_return;
}

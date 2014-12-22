%{
#include <iostream>

extern "C"
{
        int yyparse(void);
        int yylex(void);  
        int yywrap()
        {
                return 1;
        }

}

/*#include "command.tab.h"*/
%}

%option noinput  
%option nounput

%x STRING
%x LINE_COMMENT
%x MULTI_COMMENT

digit				[0-9]
hex				[0-9A-Fa-f]
letter				[a-zA-Z]
underscore			[_]
non_digit			({letter}|{underscore})
identifier			({non_digit}({non_digit}|{digit})*)

%%

\'[\\]?[^\'\n\t]\'		{ std::cout << "CHAR = " << yytext; }

\"				{ BEGIN(STRING); }
<STRING>[^\"]+			{ std::cout << "STRING = " << yytext; }
<STRING>\"			{ BEGIN(INITIAL); }

\/\/				{ BEGIN(LINE_COMMENT); }
<LINE_COMMENT>[^\n]+		;
<LINE_COMMENT>\n		{ BEGIN(INITIAL); };

\/\*				{ BEGIN(MULTI_COMMENT); }
<MULTI_COMMENT>(^\*\/)*		;
<MULTI_COMMENT>\*\/		{ BEGIN(INITIAL); }

enum				{ std::cout << "ENUM"; }

class				{ std::cout << "CLASS"; }
struct				{ std::cout << "STRUCT"; }

public				{ std::cout << "PUBLIC"; }

=				{ std::cout << "EQUAL"; }

{digit}+				{ std::cout << "DIGIT"; }
{letter}+				{ std::cout << "NON_DIGIT"; }
{identifier}				{ std::cout << "ID"; }

.				;

%%


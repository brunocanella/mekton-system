#include "gtest/gtest.h"

#include <property.hpp>
#include <string>

namespace {

using namespace mekton;

TEST( Property, Types ) {
	Property<int> l_int;

	l_int = 10;

	ASSERT_EQ( l_int, 10 );

	Property<bool> l_bool(true);

	ASSERT_EQ( l_bool, true );


	Property<std::string> l_string;
	l_string = "foo";

	ASSERT_EQ( l_string, "foo" );
}

TEST( Property, Operators ) {
	Property<int> l_num_1 = 10;
	Property<int> l_num_2 = 4;

	int l_num_3 = l_num_1 + l_num_2;

	ASSERT_EQ( l_num_3, 14 );

	ASSERT_EQ( l_num_1 * l_num_2, 40 );
}

class Bar {
public:
	Property<bool> alpha;
	Property<int> bravo;
	Property<float> charlie;
	Property<std::string> delta;

	bool is_event_triggered;

	Bar( int a_num ) : bravo(a_num), is_event_triggered(false) {
		charlie.on_after_set = std::bind( &Bar::on_after_set, this );
	}

	void on_after_set() {
		is_event_triggered = true;
	}

};

TEST( Property, Class ) {
	Bar bar(-8);
	bar.alpha = true;
	bar.charlie = 15.2f;
	bar.delta = "delta";

	ASSERT_EQ( bar.is_event_triggered, true );
	ASSERT_EQ( bar.alpha, true );
	ASSERT_EQ( bar.bravo, -8 );
	ASSERT_EQ( bar.charlie, static_cast<float>(15.2) );
	ASSERT_EQ( bar.delta, "delta" );
}

}  // namespace


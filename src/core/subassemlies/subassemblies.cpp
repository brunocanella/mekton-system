#include "subassemblies.hpp"

#include <algorithm>

#include <ensure.hpp>
#include "../servos/servo.hpp"

namespace mekton {

Subassemblies::Subassemblies( const Servo& a_owner ) : m_owner(a_owner) {
}

Subassemblies::~Subassemblies() {
}

void Subassemblies::add( PtrSubassembly a_item ) {
	ensure( a_item != nullptr && "Can't add a null pointer" );

	decimal l_new_total_space = total_space() + a_item->space();

	ensure(
		l_new_total_space <= m_owner.space() &&
		"Maximun space capacity has been exceeded"
	);

	m_subassembly_list.push_back( a_item );
}

void Subassemblies::remove( uint a_index ) {
	m_subassembly_list.erase( m_subassembly_list.begin() + a_index );
}

void Subassemblies::remove( PtrSubassembly a_item ) {
	ensure( a_item != nullptr && "Can't remove a null pointer" );

	auto l_iterator = std::find( m_subassembly_list.begin(), m_subassembly_list.end(), a_item );

	if( l_iterator != m_subassembly_list.end() ) {
		m_subassembly_list.erase( l_iterator );
	}
}

size_t Subassemblies::count() {
	return m_subassembly_list.size();
}

PtrSubassembly Subassemblies::get(int a_index) {
	return m_subassembly_list[a_index];
}

decimal Subassemblies::total_cp() const {
	decimal l_total_cp = 0;
	for( auto l_subassembly_ptr : m_subassembly_list ) {
		l_total_cp = l_subassembly_ptr->cp();
	}
	return l_total_cp;
}

decimal Subassemblies::total_weight() const {
	decimal l_total_weight = 0;
	for( auto l_subassembly_ptr : m_subassembly_list ) {
		l_total_weight = l_subassembly_ptr->weight();
	}
	return l_total_weight;
}

uint Subassemblies::total_space() const {
	decimal l_total_space = 0;
	for( auto l_subassembly_ptr : m_subassembly_list ) {
		l_total_space = l_subassembly_ptr->space();
	}
	return l_total_space;
}

const Servo& Subassemblies::owner() const {
	return m_owner;
}

} /*namespace mekton*/

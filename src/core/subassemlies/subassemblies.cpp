#include "subassemblies.hpp"

#include <algorithm>

#include <messages/warning.hpp>
#include "../servos/servo.hpp"

namespace mekton {

Subassemblies::Subassemblies( Servo& a_owner ) : m_owner(a_owner) {
}

Subassemblies::~Subassemblies() {
	for( auto l_kv : *this ) {
		dealloc( l_kv.first );
	}
}

void Subassemblies::alloc( Subassembly* a_ptr ) {
	warning( a_ptr != nullptr && "Can't add a null pointer" );
	alloc( a_ptr, a_ptr->space() );
}

void Subassemblies::alloc( Subassembly* a_ptr, uint a_value ) {
	warning( a_ptr != nullptr && "Can't add a null pointer" );

	if( !this->emplace( a_ptr, a_value ).second ) {
		dealloc( a_ptr );
		alloc( a_ptr, a_value );
		return;
	} else {
		a_ptr->alloc_space( m_owner, a_value );
	}
}

void Subassemblies::dealloc( Subassembly* a_ptr ) {
	auto l_it = find( a_ptr );
	if( l_it == end() ) {
		return;
	}
	a_ptr->dealloc_space( m_owner, l_it->second );
	erase( l_it );
}

decimal Subassemblies::total_cost() const {
	decimal l_total_cp = 0;
	for( auto l_kv : *this ) {
		l_total_cp += l_kv.first->cost();
	}
	return l_total_cp;
}

decimal Subassemblies::total_weight() const {
	decimal l_total_weight = 0;
	for( auto l_kv : *this ) {
		decimal l_space = l_kv.first->space();
		decimal l_alloced_space = decimal(l_kv.second) > l_space ? l_space : decimal(l_kv.second);
		decimal l_space_ratio = l_space == 0 ? 1 : l_alloced_space / l_space;
		l_total_weight += l_kv.first->weight() * l_space_ratio;
	}
	return l_total_weight;
}

uint Subassemblies::total_space() const {
	decimal l_total_space = 0;
	for( auto l_kv : *this ) {
		l_total_space += l_kv.second;
	}
	return l_total_space;
}

const Servo& Subassemblies::owner() const {
	return m_owner;
}

} /*namespace mekton*/

#include "subassembly.hpp"

#include "../servos/servo.hpp"

namespace mekton {

Subassembly::Subassembly(string a_name, decimal a_cost, decimal a_weight, uint a_kills, uint a_space , string a_description) :
	Subassembly( a_name, a_cost, a_weight, a_kills, a_space, a_space, a_description ) {
}

Subassembly::Subassembly(
	string a_name,
	decimal a_cost,
	decimal a_weight,
	uint a_kills,
	uint a_space,
	uint a_space_to_alloc,
	string a_description ) :
	m_name(a_name),
	m_description(a_description),
	m_cost(a_cost),
	m_weight(a_weight),
	m_kills(a_kills),
	m_space(a_space),
	m_space_to_alloc(a_space_to_alloc) {
}

Subassembly::~Subassembly() {
	for( auto l_servo_ptr : m_in_servos ) {
		l_servo_ptr->subassemblies().dealloc( this );
	}
}

void Subassembly::alloc_space(Servo& a_servo, uint a_alloc) {
	m_in_servos.insert( &a_servo );
	m_space_to_alloc -= a_alloc;
}

void Subassembly::dealloc_space(Servo& a_servo, uint a_dealloc) {
	m_in_servos.erase( &a_servo );
	m_space_to_alloc += a_dealloc;
}

string Subassembly::name() const {
	return m_name;
}

void Subassembly::name(const string& a_name) {
	m_name = a_name;
}

string Subassembly::description() const {
	return m_description;
}

void Subassembly::description(const string& a_description) {
	m_description = a_description;
}

decimal Subassembly::cost() const {
	return m_cost;
}

void Subassembly::cost(const decimal& a_cost) {
	m_cost = a_cost;
}

decimal Subassembly::weight() const {
	return m_weight;
}

void Subassembly::weight(const decimal& a_weight) {
	m_weight = a_weight;
}

uint Subassembly::kills() const {
	return m_kills;
}

void Subassembly::kills(const uint& a_kills) {
	m_kills = a_kills;
}

uint Subassembly::space() const {
	return m_space;
}

void Subassembly::space(const uint& a_space) {
	m_space = a_space;
}
uint Subassembly::space_to_alloc() const
{
	return m_space_to_alloc;
}

} /*namespace mekton*/

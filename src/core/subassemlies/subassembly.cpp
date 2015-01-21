#include "subassembly.hpp"

namespace mekton {

Subassembly::Subassembly(string a_name, decimal a_cost, decimal a_weight, uint a_kills, uint a_space , string a_description) :
	 m_name(a_name), m_cost(a_cost), m_weight(a_weight), m_kills(a_kills), m_space(a_space), m_description(a_description) {
}

Subassembly::~Subassembly() {
}

string Subassembly::name() const {
	return m_name;
}

void Subassembly::name(const string& a_name) {
	m_name = a_name;
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

string Subassembly::description() const {
	return m_description;
}

void Subassembly::description(const string& a_description) {
	m_description = a_description;
}

} /*namespace mekton*/

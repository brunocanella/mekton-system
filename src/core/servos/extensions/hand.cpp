#include "hand.hpp"

namespace mekton {

Hand::Hand(
	string a_description,
	decimal a_cost,
	uint a_space,
	uint a_damage,
	uint a_kills,
	bool a_manipulation
) :
	m_description(a_description),
	m_cost(a_cost),
	m_space(a_space),
	m_damage(a_damage),
	m_kills(a_kills),
	m_weight( static_cast<decimal>(m_kills) / 2.f ),
	m_manipulation(a_manipulation) {
}

Hand::~Hand() {
}

string Hand::description() const {
	return m_description;
}

void Hand::description(const string& a_description) {
	m_description = a_description;
}

decimal Hand::cost() const {
	return m_cost;
}

void Hand::cost(const decimal& a_cost) {
	m_cost = a_cost;
}

uint Hand::space() const {
	return m_space;
}

void Hand::space(const uint& a_space) {
	m_space = a_space;
}

uint Hand::damage() const {
	return m_damage;
}

void Hand::damage(const uint& a_damage) {
	m_damage = a_damage;
}

uint Hand::kills() const {
	return m_kills;
}

void Hand::kills(const uint& a_kills) {
	m_kills = a_kills;
}

decimal Hand::weight() const {
	return m_weight;
}

void Hand::weight(const decimal& a_weight) {
	m_weight = a_weight;
}

bool Hand::manipulation() const {
	return m_manipulation;
}

void Hand::manipulation(bool a_manipulation) {
	m_manipulation = a_manipulation;
}

} /*namespace mekton*/

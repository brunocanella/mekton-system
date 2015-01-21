#include "hand.hpp"

namespace mekton {

Hand::Hand(
	std::string a_description,
	decimal a_cp,
	decimal a_weight,
	std::uint32_t a_space,
	std::uint32_t a_damage,
	std::uint32_t a_kills,
	bool a_manipulation
) :
	m_description(a_description),
	m_cp(a_cp),
	m_weight(a_weight),
	m_space(a_space),
	m_damage(a_damage),
	m_kills(a_kills),
	m_manipulation(a_manipulation) {
}

Hand::~Hand() {
}

std::string Hand::description() const {
	return m_description;
}

void Hand::description(const std::string& a_description) {
	m_description = a_description;
}

decimal Hand::cp() const {
	return m_cp;
}

void Hand::cp(const decimal& a_cp) {
	m_cp = a_cp;
}
decimal Hand::weight() const {
	return m_weight;
}

void Hand::weight(const decimal& a_weight) {
	m_weight = a_weight;
}
std::uint32_t Hand::space() const {
	return m_space;
}

void Hand::space(const std::uint32_t& a_space) {
	m_space = a_space;
}
std::uint32_t Hand::damage() const {
	return m_damage;
}

void Hand::damage(const std::uint32_t& a_damage) {
	m_damage = a_damage;
}
std::uint32_t Hand::kills() const {
	return m_kills;
}

void Hand::kills(const std::uint32_t& a_kills) {
	m_kills = a_kills;
}

bool Hand::manipulation() const {
	return m_manipulation;
}

void Hand::manipulation(bool a_manipulation) {
	m_manipulation = a_manipulation;
}

} /*namespace mekton*/

#include "foot.hpp"

namespace mekton {

Foot::Foot(string a_description,
	decimal a_cp,
	uint a_space,
	uint a_damage,
	uint a_kills,
	sint a_ma_penalty
) :
	m_description(a_description),
	m_cp(a_cp),
	m_space(a_space),
	m_damage(a_damage),
	m_kills(a_kills),
	m_weight( static_cast<decimal>(m_kills) / 2.f ),
	m_ma_penalty(a_ma_penalty) {
}

Foot::~Foot() {
}

string Foot::description() const {
	return m_description;
}

void Foot::description(const string& a_description) {
	m_description = a_description;
}

decimal Foot::cp() const {
	return m_cp;
}

void Foot::cp(const decimal& a_cp) {
	m_cp = a_cp;
}

decimal Foot::weight() const {
	return m_weight;
}

void Foot::weight(const decimal& a_weight) {
	m_weight = a_weight;
}

uint Foot::space() const {
	return m_space;
}

void Foot::space(const uint& a_space) {
	m_space = a_space;
}

uint Foot::damage() const {
	return m_damage;
}

void Foot::damage(const uint& a_damage) {
	m_damage = a_damage;
}

uint Foot::kills() const {
	return m_kills;
}

void Foot::kills(const uint& a_kills) {
	m_kills = a_kills;
}

sint Foot::ma_penalty() const {
	return m_ma_penalty;
}

void Foot::ma_penalty(sint a_ma_penalty) {
	m_ma_penalty = a_ma_penalty;
}

} /*namespace mekton*/

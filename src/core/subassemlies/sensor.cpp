#include "sensor.hpp"

namespace mekton {

Sensor::Sensor(
	string a_name,
	uint a_combat_range,
	uint a_communication_range,
	decimal a_cost,
	decimal a_weight,
	uint a_kills,
	uint a_space,
	string a_description ) :
	Subassembly(a_name, a_cost, a_weight, a_kills, a_space, a_description ),
	m_combat_range(a_combat_range),
	m_communication_range(a_communication_range) {
}

Sensor::~Sensor() {
}

uint Sensor::combat_range() const {
	return m_combat_range;
}

void Sensor::combat_range(const uint& a_combat_range) {
	m_combat_range = a_combat_range;
}

uint Sensor::communication_range() const {
	return m_communication_range;
}

void Sensor::communication_range(const uint& a_communication_range) {
	m_communication_range = a_communication_range;
}

} /*namespace mekton*/

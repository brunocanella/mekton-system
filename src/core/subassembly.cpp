/*
 * subassembly.cpp
 *
 *  Created on: May 19, 2014
 *      Author: bruno
 */

#include "subassembly.hpp"

namespace mekton
{

Subassembly::Subassembly( float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space ) :
		MechaStats( a_cp, a_weight, a_kills, a_space ) {
}

Subassembly::~Subassembly() {
}

void Subassembly::refresh() {
}

Sensor::Sensor( std::uint32_t a_range, float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space ) :
		Subassembly( a_cp, a_weight, a_kills, a_space ), m_range( a_range ) {
}

Sensor::~Sensor() {
}

Cockpit::Cockpit( std::uint32_t a_crew, float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space ) :
		Subassembly( a_cp, a_weight, a_kills, a_space ), m_crew( a_crew ) {
}

Cockpit::~Cockpit() {
}

Weapom::Weapom( std::uint32_t a_range, std::uint32_t a_weapon_accuracy, std::uint32_t a_defense_accuracy, std::uint32_t a_damage,
		std::int32_t a_shots, std::uint32_t a_burst_value, std::uint32_t a_stopping_power, float a_cp, float a_weight,
		std::uint32_t a_kills, std::uint32_t a_space ) :
		Subassembly( a_cp, a_weight, a_kills, a_space ), m_range( a_range ), m_weapon_accuracy( a_weapon_accuracy ), m_defense_accuracy(
				a_defense_accuracy ), m_damage( a_damage ), m_shots( a_shots ), m_burst_value( a_burst_value ), m_stopping_power(
				a_stopping_power ) {

}

Weapom::~Weapom() {

}

} /* namespace mekton */

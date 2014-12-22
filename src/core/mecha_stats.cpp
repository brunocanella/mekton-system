/*
 * mecha_stats.cpp
 *
 *  Created on: May 18, 2014
 *      Author: bruno
 */

#include "mecha_stats.hpp"

namespace mekton
{

MechaStats::MechaStats() :
	m_cp( 0.f ), m_weight( 0.f ), m_kills( 0 ), m_space( 0 ) {
}

MechaStats::MechaStats( float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space ) :
		m_cp( a_cp ), m_weight( a_weight ), m_kills( a_kills ), m_space( a_space ) {
}

MechaStats::~MechaStats() {
}

} /* namespace mekton */

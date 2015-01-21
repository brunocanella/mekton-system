/*
 * mecha_stats.hpp
 *
 *  Created on: May 18, 2014
 *      Author: bruno
 */

#ifndef MECHA_STATS_HPP_
#define MECHA_STATS_HPP_

#include <cstdint>

namespace mekton
{

class MechaStats
{
public:
	MechaStats();
	MechaStats( float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space );
	virtual ~MechaStats();

	virtual void refresh() = 0;

	virtual float get_cp() const {
		return m_cp;
	}

	virtual std::uint32_t get_kills() const {
		return m_kills;
	}

	virtual std::uint32_t get_space() const {
		return m_space;
	}

	virtual float get_weight() const {
		return m_weight;
	}

protected:
	float m_cp;
	float m_weight;
	std::uint32_t m_kills;
	std::uint32_t m_space;

};

} /* namespace mekton */

#endif /* MECHA_STATS_HPP_ */

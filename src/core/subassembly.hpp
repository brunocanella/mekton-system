/*
 * subassembly.hpp
 *
 *  Created on: May 19, 2014
 *      Author: bruno
 */

#ifndef SUBASSEMBLY_HPP_
#define SUBASSEMBLY_HPP_

#include "mecha_stats.hpp"

#include <cstdint>

namespace mekton
{

class Subassembly : public MechaStats
{
public:
	Subassembly( float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space );
	virtual ~Subassembly();
	void refresh();
};
typedef Subassembly* PtrSubassembly;

class Sensor : public Subassembly
{
public:
	Sensor( std::uint32_t a_range, float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space );
	virtual ~Sensor();

	std::uint32_t get_range() const {
		return m_range;
	}
protected:
	std::uint32_t m_range;
};

class Cockpit : public Subassembly
{
public:
	Cockpit( std::uint32_t a_crew, float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space );
	virtual ~Cockpit();

	std::uint32_t get_crew() const {
		return m_crew;
	}

protected:
	std::uint32_t m_crew;
};

class Weapom : public Subassembly
{
public:
	Weapom( std::uint32_t a_range, std::uint32_t a_weapon_accuracy, std::uint32_t a_defense_accuracy, std::uint32_t a_damage,
			std::int32_t a_shots, std::uint32_t a_burst_value, std::uint32_t a_stopping_power, float a_cp, float a_weight,
			std::uint32_t a_kills, std::uint32_t a_space );
	virtual ~Weapom();

	std::uint32_t get_burst_value() const {
		return m_burst_value;
	}

	std::uint32_t get_damage() const {
		return m_damage;
	}

	std::uint32_t get_defense_accuracy() const {
		return m_defense_accuracy;
	}

	std::uint32_t get_range() const {
		return m_range;
	}

	std::int32_t get_shots() const {
		return m_shots;
	}

	std::uint32_t get_stopping_power() const {
		return m_stopping_power;
	}

	std::uint32_t get_weapon_accuracy() const {
		return m_weapon_accuracy;
	}

protected:
	std::uint32_t m_range;
	std::uint32_t m_weapon_accuracy;
	std::uint32_t m_defense_accuracy;
	std::uint32_t m_damage;
	std::int32_t m_shots;
	std::uint32_t m_burst_value;
	std::uint32_t m_stopping_power;
};

} /* namespace mekton */

#endif /* SUBASSEMBLY_HPP_ */

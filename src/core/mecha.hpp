/*
 * mecha.hpp
 *
 *  Created on: May 18, 2014
 *      Author: bruno
 */

#ifndef MECHA_HPP_
#define MECHA_HPP_

#include <cstdint>
#include <vector>

#include "servo.hpp"

namespace mekton
{

class Mecha
{
public:
	enum class Form : std::uint8_t {
		Mekton,
		MechaBeast,
		MechaTank,
		MechaFighter
	};

	Mecha();
	virtual ~Mecha();

	float get_frame_weight() const;

	float get_total_cp() const;

	std::vector<std::shared_ptr<Servo> >& get_servos() {
		return m_servos;
	}
protected:
	std::vector<std::shared_ptr<Servo>> m_servos;
};

} /* namespace mekton */

#endif /* MECHA_HPP_ */

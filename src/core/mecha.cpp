/*
 * mecha.cpp
 *
 *  Created on: May 18, 2014
 *      Author: bruno
 */

#include "mecha.hpp"

namespace mekton
{

Mecha::Mecha() {
	// TODO Auto-generated constructor stub
}

Mecha::~Mecha() {
	// TODO Auto-generated destructor stub
}

float Mecha::get_frame_weight() const {
	float l_frame_weight = 0;

	for ( auto lp_servo : m_servos ) {
		l_frame_weight += lp_servo->get_weight();
		l_frame_weight += lp_servo->get_armor().get_weight();
	}

	return l_frame_weight;
}

float Mecha::get_total_cp() const {
	float l_cp = 0;

	for ( auto lp_servo : m_servos ) {
		l_cp += lp_servo->get_cp();
		l_cp += lp_servo->get_armor().get_cp();
	}

	return l_cp;
}



} /* namespace mekton */

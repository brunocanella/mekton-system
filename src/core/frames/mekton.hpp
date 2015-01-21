#ifndef MEKTON_HPP_
#define MEKTON_HPP_

#include "frame.hpp"
#include "../servos/servos.hpp"

namespace mekton {

class Mekton : public Frame {
public:
	Mekton(
		string a_description,
		Model a_frame_model,
		Model a_armor_model
	);
	~Mekton();

	Head& head() const;

	Torso& torso() const;

	Arm& arm_left() const;

	Arm& arm_right() const;

	Leg& leg_left() const;

	Leg& leg_right() const;

private:
	Head& m_head;
	Torso& m_torso;
	Arm& m_arm_left;
	Arm& m_arm_right;
	Leg& m_leg_left;
	Leg& m_leg_right;

};

} /*namespace mekton*/

#endif // MEKTON_HPP_

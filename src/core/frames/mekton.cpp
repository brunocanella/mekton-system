#include "mekton.hpp"

namespace mekton {

Mekton::Mekton( string a_description, Model a_frame_model, Model a_armor_model ) :
	Frame( BodyForm::Mekton, a_description, {
		PtrHead(new Head( "Head", a_frame_model, PtrArmor(new Armor(a_armor_model)), 0 )),
		PtrTorso(new Torso( "Torso", a_frame_model, PtrArmor(new Armor(a_armor_model)), 0, {} )),
		PtrArm(new Arm( "L. Arm", a_frame_model, PtrArmor(new Armor(a_armor_model)), 0, PtrHand(new Hand(c_hand_normal)) )),
		PtrArm(new Arm( "R. Arm", a_frame_model, PtrArmor(new Armor(a_armor_model)), 0, PtrHand(new Hand(c_hand_normal))  )),
		PtrLeg(new Leg( "L. Leg", a_frame_model, PtrArmor(new Armor(a_armor_model)), 0, PtrFoot(new Foot(c_foot_normal)) )),
		PtrLeg(new Leg( "R. Leg", a_frame_model, PtrArmor(new Armor(a_armor_model)), 0, PtrFoot(new Foot(c_foot_normal)) )),
	} ),
	m_head( *static_cast<Head*>(servos()[0].get()) ),
	m_torso( *static_cast<Torso*>(servos()[1].get()) ),
	m_arm_left( *static_cast<Arm*>(servos()[2].get()) ),
	m_arm_right( *static_cast<Arm*>(servos()[3].get()) ),
	m_leg_left( *static_cast<Leg*>(servos()[4].get()) ),
	m_leg_right( *static_cast<Leg*>(servos()[5].get()) ) {
	auto& l_torso_attached = m_torso.attached_servos();
	l_torso_attached.push_back(&m_head);
	l_torso_attached.push_back(&m_arm_left);
	l_torso_attached.push_back(&m_arm_right);
	l_torso_attached.push_back(&m_leg_left);
	l_torso_attached.push_back(&m_leg_right);
}

Mekton::~Mekton() {
}

Head& Mekton::head() const {
	return m_head;
}

Torso& Mekton::torso() const {
	return m_torso;
}

Arm& Mekton::arm_left() const {
	return m_arm_left;
}

Arm& Mekton::arm_right() const {
	return m_arm_right;
}

Leg& Mekton::leg_left() const {
	return m_leg_left;
}

Leg& Mekton::leg_right() const {
	return m_leg_right;
}

} /*namespace mekton*/

#include "torso.hpp"

#include <sstream>
#include <stdexcept>
#include <messages/ensure.hpp>

namespace mekton {

Torso::Torso(
	string a_description,
	Model a_model,
	PtrArmor a_armor_ptr,
	uint a_extra_space_factor,
	std::vector<Servo*> a_attached_servos ) :
	Servo( Type::Torso, a_description, a_model, a_armor_ptr, a_extra_space_factor ),
	m_attached_servos(a_attached_servos) {
	update();
}

Torso::~Torso() {
}

bool Torso::validate() {
	for( Servo* lp_servo : m_attached_servos ) {
		switch ( lp_servo->type() ) {
		case Type::Torso:
			status_error( "A torso cannot be attached to another torso!" );
			return false;
		case Type::Arm:
		case Type::Head:
		case Type::Tail:
		case Type::Wing:
			if( lp_servo->model().value > (m_model.value + 1) ) {
				std::stringstream l_ss_servos;
				l_ss_servos << "Servo ["
							<< lp_servo->description() << " : " << lp_servo->model().description
							<< "] attached to torso ["
							<< m_description << " : " << m_model.description
							<< "] cannot be higher than one level of the torso.";
				status_error( l_ss_servos.str() );
				return false;
			}
			break;
		case Type::Leg:
			if( lp_servo->model().value < (m_model.value-1) ) {
				std::stringstream l_ss_leg;
				l_ss_leg << "Leg ["
						 << lp_servo->description() << " : " << lp_servo->model().description
						 << "] attached to torso ["
						 << m_description << " : " << m_model.description
						 << "] must be one level lower or higher than the torso";
				status_error( l_ss_leg.str() );
				return false;
			}
		case Type::Pod:
			break;
		default:
			ensure( !"Unkown servo type!" );
			break;
		}
	}

	return Servo::validate();
}

void Torso::update() {
	uint l_base = m_model.value * 2;

	m_cost = static_cast<decimal>(l_base);
	m_space = l_base;
	m_kills = l_base;

	Servo::update();
}

std::vector<Servo*>& Torso::attached_servos() {
	return m_attached_servos;
}

} /* namespace mekton */

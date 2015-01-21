#ifndef TORSO_HPP_
#define TORSO_HPP_

#include "servo.hpp"

namespace mekton {

class Torso : public Servo {
public:
	Torso(
		string a_description,
		Model a_model,
		PtrArmor a_armor_ptr,
		uint a_extra_space_factor,
		std::vector<Servo*> a_attached_servos );
	virtual ~Torso();

	bool validate();

	void update();

	std::vector<Servo*>& attached_servos();

private:
	std::vector<Servo*> m_attached_servos;
};

typedef std::shared_ptr<Torso> PtrTorso;

} /* namespace mekton */

#endif // TORSO_HPP_

#ifndef WING_HPP_
#define WING_HPP_

#include "servo.hpp"

namespace mekton {

class Wing : public Servo
{
public:
	Wing( string a_description, Model a_model, PtrArmor a_armor_ptr, uint a_extra_space_factor );
	virtual ~Wing();

	bool validate();

	void update();
};

typedef std::shared_ptr<Wing> PtrWing;

} /* namespace mekton */

#endif // WING_HPP_

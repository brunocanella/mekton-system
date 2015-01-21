#ifndef TAIL_HPP_
#define TAIL_HPP_

#include "servo.hpp"

namespace mekton {

class Tail : public Servo
{
public:
	Tail( string a_description, Model a_model, PtrArmor a_armor_ptr, uint a_extra_space_factor );
	virtual ~Tail();

	bool validate();

	void update();
};

typedef std::shared_ptr<Tail> PtrTail;

} /* namespace mekton */

#endif // TAIL_HPP_

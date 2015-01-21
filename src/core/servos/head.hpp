#ifndef HEAD_HPP_
#define HEAD_HPP_

#include "servo.hpp"

namespace mekton {

class Head : public Servo
{
public:
	Head( string a_description, Model a_model, PtrArmor a_armor_ptr, uint a_extra_space_factor );
	virtual ~Head();

	bool validate();

	void update();
};

typedef std::shared_ptr<Head> PtrHead;

} /* namespace mekton */

#endif // HEAD_HPP_

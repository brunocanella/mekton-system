#ifndef HEAD_HPP_
#define HEAD_HPP_

#include "servo.hpp"

namespace mekton {

class Head : public Servo
{
public:
	Head( Model a_model, Armor a_armor );
	virtual ~Head();
	void refresh();
};

} /* namespace mekton */

#endif // HEAD_HPP_

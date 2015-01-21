#ifndef WING_HPP_
#define WING_HPP_

#include "servo.hpp"

namespace mekton {

class Wing : public Servo
{
public:
	Wing( Model a_model, Armor a_armor );
	virtual ~Wing();
	void refresh();
};

} /* namespace mekton */

#endif // WING_HPP_

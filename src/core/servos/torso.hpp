#ifndef TORSO_HPP_
#define TORSO_HPP_

#include "servo.hpp"

namespace mekton {

class Torso : public Servo
{
public:
	Torso( Model a_model, Armor a_armor );
	virtual ~Torso();
	virtual void refresh();
};

} /* namespace mekton */

#endif // TORSO_HPP_

#ifndef TAIL_HPP_
#define TAIL_HPP_

#include "servo.hpp"

namespace mekton {

class Tail : public Servo
{
public:
	Tail( Model a_model, Armor a_armor );
	virtual ~Tail();
	void refresh();
};

} /* namespace mekton */

#endif // TAIL_HPP_

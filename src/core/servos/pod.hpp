#ifndef POD_HPP_
#define POD_HPP_

#include "servo.hpp"

namespace mekton {

class Pod : public Servo
{
public:
	Pod( Model a_model, Armor a_armor );
	virtual ~Pod();
	void refresh();
};

} /* namespace mekton */

#endif // POD_HPP_

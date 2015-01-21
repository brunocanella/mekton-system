#ifndef POD_HPP_
#define POD_HPP_

#include "servo.hpp"

namespace mekton {

class Pod : public Servo
{
public:
	Pod( string a_description, Model a_model, PtrArmor a_armor_ptr, uint a_extra_space_factor );
	virtual ~Pod();

	bool validate();

	void update();
protected:
	bool validate_minimun_armor();
};

typedef std::shared_ptr<Pod> PtrPod;

} /* namespace mekton */

#endif // POD_HPP_

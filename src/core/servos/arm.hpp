#ifndef ARM_HPP_
#define ARM_HPP_

#include "servo.hpp"

namespace mekton {

class Arm : public Servo
{
public:
	Arm( Model a_model, Armor a_armor, PtrArmExtremity ap_arm );
	virtual ~Arm();
	void refresh();

	std::uint32_t get_add() const {
		return m_add;
	}

	std::uint32_t get_throw() const {
		return m_throw;
	}

	std::shared_ptr<ArmExtremity> get_arm_extremity() const {
		return mp_arm;
	}

protected:
	std::shared_ptr<ArmExtremity> mp_arm;
	std::int32_t m_add;
	std::uint32_t m_throw;
};

} /* namespace mekton */

#endif // ARM_HPP_

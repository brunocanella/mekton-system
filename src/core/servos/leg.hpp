#ifndef LEG_HPP_
#define LEG_HPP_

#include "servo.hpp"

namespace mekton {

class Leg : public Servo
{
public:
	Leg( Model a_model, Armor a_armor, PtrLegExtremity ap_Leg );
	Leg( Model a_model, Armor a_armor, std::shared_ptr<LegExtremity> ap_Leg = cp_foot );
	virtual ~Leg();
	void refresh();

	std::int32_t get_add() const {
		return m_add;
	}

	std::shared_ptr<LegExtremity> get_leg_extremity() const {
		return mp_leg;
	}
protected:
	std::shared_ptr<LegExtremity> mp_leg;
	std::int32_t m_add;
};

} /* namespace mekton */

#endif // LEG_HPP_

#ifndef LEG_HPP_
#define LEG_HPP_

#include "servo.hpp"
#include "extensions/foot.hpp"

namespace mekton {

class Leg : public Servo {
public:
	Leg( string a_description, Model a_model, PtrArmor a_armor_ptr, uint a_extra_space_factor, PtrFoot a_foot_ptr );
	virtual ~Leg();

	bool validate();

	void update();

	PtrFoot foot_ptr() const;
	void foot_ptr(const PtrFoot& a_foot_ptr );

	sint add() const;

	decimal total_cost() const;

	decimal frame_weight() const;

	decimal total_weight() const;

	sint free_space() const;
protected:
	PtrFoot m_foot_ptr;
	sint m_add;

private:
	bool validate_foot();
};

typedef std::shared_ptr<Leg> PtrLeg;

} /* namespace mekton */

#endif // LEG_HPP_

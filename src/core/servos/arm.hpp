#ifndef ARM_HPP_
#define ARM_HPP_

#include "servo.hpp"
#include "extensions/hand.hpp"

namespace mekton {

class Arm : public Servo {
public:
	Arm( string a_description, Model a_model, PtrArmor a_armor_ptr, uint a_extra_space_factor, PtrHand a_hand_ptr );
	virtual ~Arm();

	bool validate();

	void update();

	PtrHand hand_ptr() const;
	void hand_ptr(const PtrHand& a_hand_ptr );

	sint add() const;

	uint throw_dist() const;

	decimal total_cost() const;

	decimal frame_weight() const;

	decimal total_weight() const;

	sint free_space() const;
protected:
	PtrHand m_hand_ptr;
	sint m_add;
	uint m_throw_dist;
private:
};

typedef std::shared_ptr<Arm> PtrArm;

} /* namespace mekton */

#endif // ARM_HPP_

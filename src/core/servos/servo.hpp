/*
 * servo.hpp
 *
 *  Created on: May 18, 2014
 *      Author: bruno
 */

#ifndef SERVO_HPP_
#define SERVO_HPP_

#include <string>
#include <memory>
#include <vector>

#include <typedefs.hpp>

#include "../interfaces/validatable.hpp"
#include "../subassemlies/subassemblies.hpp"
#include "armor.hpp"

namespace mekton {

class Servo : public Validatable {
public:
	enum class Type : uint {
		Head,
		Torso,
		Arm,
		Leg,
		Wing,
		Tail,
		Pod
	};

	Servo( const Type a_type, string a_description, Model a_model, PtrArmor a_armor_ptr, uint a_extra_space_factor );
	virtual ~Servo();

	virtual bool validate();

	/**
	 * @brief Updates the dependent stats.
	 * @remark When implementing this method in a superclass, make the call to the base version
	 * before you sum any extra values to the default base stats.
	 */
	virtual void update();

	Subassemblies& subassemblies();

	Type type() const;

	string description() const;
	void description(const string& a_description);

	Model model() const;
	void model(const Model& a_model);

	PtrArmor armor_ptr() const;
	void armor_ptr(const PtrArmor& a_armor_ptr);

	uint extra_space_factor() const;
	void extra_space_factor(const uint& a_extra_space_factor);

	decimal cost() const;

	decimal weight() const;

	uint kills() const;

	uint space() const;

	decimal total_cost() const;

	virtual decimal frame_weight() const;

	virtual decimal total_weight() const;

	virtual sint free_space() const;

protected:
	Subassemblies m_subassemblies;

	const Type m_type;
	string m_description;
	Model m_model;
	PtrArmor m_armor_ptr;
	uint m_extra_space_factor;

	decimal m_cost;
	decimal m_weight;
	uint m_kills;
	uint m_space;

private:
	bool validate_armor_limit();
	bool validate_extra_space_factor();
	bool validate_free_space_positive();
};

typedef std::shared_ptr<Servo> PtrServo;

} /* namespace mekton */

#endif /* SERVO_HPP_ */

/*
 * servo.hpp
 *
 *  Created on: May 18, 2014
 *      Author: bruno
 */

#ifndef SERVO_HPP_
#define SERVO_HPP_

#include "mecha_stats.hpp"

#include <cstdint>
#include <exception>
#include <cassert>
#include <string>
#include <memory>
#include <vector>

#include "subassembly.hpp"

namespace mekton
{

enum class Model : std::uint8_t {
	SuperLight,
	LightWeight,
	Striker,
	MediumStriker,
	HeavyStriker,
	MediumWeight,
	LightHeavy,
	MediumHeavy,
	ArmoredHeavy,
	SuperHeavy,
	MegaHeavy,
	Count
};

class Armor : public MechaStats
{
public:
	Armor( Model a_model );
	~Armor();
	void refresh();



	std::uint32_t get_model_num() const {
		return static_cast<std::uint32_t>(m_model);
	}

	Model get_model() const {
		return m_model;
	}

	std::uint32_t get_stopping_power() const {
		return m_stopping_power;
	}
private:
	Model m_model;
	std::uint32_t m_stopping_power;
};

class Servo : public MechaStats
{
public:
	Servo( Model a_model, Armor a_armor );
	virtual ~Servo();

	virtual void refresh() = 0;

	void assert_armor_limit();

	virtual std::uint32_t get_kills() const {
		return m_kills - m_extra_space_factor;
	}

	virtual std::uint32_t get_space() const {
		return m_space + m_extra_space_factor * 2;
	}

	std::uint32_t get_model_num() const {
			return static_cast<std::uint32_t>(m_model);
	}

	Model get_model() const {
		return m_model;
	}

	Armor get_armor() const {
			return m_armor;
	}

	void set_armor( const Armor& a_armor ) {
		m_armor = a_armor;
	}

	std::uint8_t get_extra_space_factor() const {
		return m_extra_space_factor;
	}

	void set_extra_space_factor( std::uint8_t a_extra_space_factor ) {
		assert( a_extra_space_factor < m_kills && "The factor can't reduce Kills to zero." );
		m_extra_space_factor = a_extra_space_factor;
	}

	std::vector<std::shared_ptr<Subassembly> >& subassemblies() {
		return m_subassemblies;
	}

private:
	Model m_model;
	Armor m_armor;
	std::uint8_t m_extra_space_factor;
	std::vector<std::shared_ptr<Subassembly>> m_subassemblies;
};

typedef std::shared_ptr<Servo> PtrServo;

class TorsoServo : public Servo
{
public:
	TorsoServo( Model a_model, Armor a_armor );
	virtual ~TorsoServo();
	virtual void refresh();
};

class ArmExtremity : public MechaStats
{
public:
	ArmExtremity( std::string a_name, std::uint32_t a_damage, bool a_manipulation, std::int32_t a_weapon_accurary, float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space );
	virtual ~ArmExtremity();
	void refresh();

	const std::string& get_name() const {
			return m_name;
	}
	std::uint32_t get_damage() const {
		return m_damage;
	}
	bool is_manipulation() const {
		return m_manipulation;
	}
	std::int32_t get_weapom_accuracy() const {
		return m_weapon_accuracy;
	}
protected:
	std::string m_name;
	std::uint32_t m_damage;
	bool m_manipulation;
	std::int32_t m_weapon_accuracy;
};
typedef ArmExtremity * PtrArmExtremity;

class ArmServo : public Servo
{
public:
	ArmServo( Model a_model, Armor a_armor, PtrArmExtremity ap_arm );
	virtual ~ArmServo();
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

class LegExtremity : public MechaStats
{
public:
	LegExtremity( std::string a_name, std::uint32_t a_damage, std::int32_t a_ma_penalty, float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space );
	virtual ~LegExtremity();
	void refresh();

	const std::string& get_name() const {
		return m_name;
	}
	std::uint32_t get_damage() const {
		return m_damage;
	}
	std::int32_t get_ma_penalty() const {
		return m_ma_penalty;
	}
protected:
	std::string m_name;
	std::uint32_t m_damage;
	std::int32_t m_ma_penalty;
};
typedef LegExtremity * PtrLegExtremity;

const std::shared_ptr<LegExtremity> cp_foot { new LegExtremity( "Foot", 2, 0, 0, 0, 0, 0 ) };

class LegServo : public Servo
{
public:
	LegServo( Model a_model, Armor a_armor, PtrLegExtremity ap_Leg );
	LegServo( Model a_model, Armor a_armor, std::shared_ptr<LegExtremity> ap_Leg = cp_foot );
	virtual ~LegServo();
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

class HeadServo : public Servo
{
public:
	HeadServo( Model a_model, Armor a_armor );
	virtual ~HeadServo();
	void refresh();
};

class WingServo : public Servo
{
public:
	WingServo( Model a_model, Armor a_armor );
	virtual ~WingServo();
	void refresh();
};

class TailServo : public Servo
{
public:
	TailServo( Model a_model, Armor a_armor );
	virtual ~TailServo();
	void refresh();
};

class PodServo : public Servo
{
public:
	PodServo( Model a_model, Armor a_armor );
	virtual ~PodServo();
	void refresh();
};

} /* namespace mekton */

#endif /* SERVO_HPP_ */

/*
 * servo.cpp
 *
 *  Created on: May 18, 2014
 *      Author: bruno
 */

#include "servo.hpp"

namespace mekton
{

Armor::Armor( Model a_model ) : MechaStats(), m_model(a_model) {
	refresh();
}

Armor::~Armor() {
}

void Armor::refresh() {
	std::uint32_t l_base = get_model_num() + 1;
	m_cp =  l_base;
	m_space = 0;
	m_kills = 0;
	m_stopping_power = l_base;
	m_weight = static_cast<float>(l_base) / 2.f;
}

Servo::Servo( Model a_model, Armor a_armor ) : MechaStats(), m_model(a_model), m_armor(a_armor), m_extra_space_factor(0), m_subassemblies() {
}

Servo::~Servo() {
}

void Servo::assert_armor_limit() {
	assert( ( m_armor.get_model_num() - get_model_num() ) > 2 && "Maximum armor level can't higher than two levels of the servo" );
}

TorsoServo::TorsoServo( Model a_model, Armor a_armor ) : Servo( a_model, a_armor ) {
	refresh();
}

TorsoServo::~TorsoServo() {
}

void TorsoServo::refresh() {
	std::uint8_t l_factor = get_model_num() + 1;
	m_cp = l_factor * 2;
	m_space = l_factor * 2;
	m_kills = l_factor * 2;
	m_weight = l_factor;
}

ArmExtremity::ArmExtremity( std::string a_name, std::uint32_t a_damage, bool a_manipulation, std::int32_t a_weapom_accurary, float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space ) :
		MechaStats( a_cp, a_weight, a_kills, a_space ), m_name(a_name), m_damage(a_damage), m_manipulation(a_manipulation), m_weapon_accuracy(a_weapom_accurary) {
}

ArmExtremity::~ArmExtremity() {
}

void ArmExtremity::refresh() {
}

ArmServo::ArmServo( Model a_model, Armor a_armor,  PtrArmExtremity ap_arm ) : Servo( a_model, a_armor ), mp_arm( ap_arm ), m_add(0), m_throw(0) {
	refresh();
}

ArmServo::~ArmServo() {
}

void ArmServo::refresh() {
	if( mp_arm != nullptr ) {
		mp_arm->refresh();
	}

	std::uint32_t l_base = get_model_num();
	m_cp =  l_base + 2;
	m_space = l_base + 2;
	if( mp_arm != nullptr ) {
		m_space -= mp_arm->get_space();
	}
	m_kills = l_base + 2;
	m_weight = static_cast<float>( l_base + 1 ) / 2.f;
	if( mp_arm != nullptr ) {
		m_weight += mp_arm->get_weight();
	}
	m_add = l_base / 3;
	m_throw = 3 + static_cast<int>( l_base / 2 );
}

LegExtremity::LegExtremity( std::string a_name, std::uint32_t a_damage, std::int32_t a_ma_penalty, float a_cp, float a_weight, std::uint32_t a_kills, std::uint32_t a_space ) :
		MechaStats( a_cp, a_weight, a_kills, a_space ), m_name(a_name), m_damage(a_damage), m_ma_penalty(a_ma_penalty) {
}

LegExtremity::~LegExtremity() {
}

void LegExtremity::refresh() {
}

LegServo::LegServo( Model a_model, Armor a_armor, std::shared_ptr<LegExtremity> ap_Leg ) : Servo( a_model, a_armor ), mp_leg( ap_Leg ), m_add(0) {
	refresh();
}

LegServo::LegServo( Model a_model, Armor a_armor, PtrLegExtremity ap_Leg ) : LegServo( a_model, a_armor, std::shared_ptr<LegExtremity>( ap_Leg ) ) {
}

LegServo::~LegServo() {
}

void LegServo::refresh() {
	assert( mp_leg != nullptr && "Foot can't be null in a leg servo." );
	mp_leg->refresh();

	std::uint32_t l_base = get_model_num();
	m_cp =  l_base + 2;
	m_space = l_base + 2;
	m_kills = l_base + 2;
	m_weight = m_cp / 2.f;
	m_weight += mp_leg->get_weight();

	m_add = l_base / 2;
}

HeadServo::HeadServo( Model a_model, Armor a_armor ) : Servo( a_model, a_armor ) {
	refresh();
}

HeadServo::~HeadServo() {
}

void HeadServo::refresh() {
	std::uint32_t l_base = get_model_num() + 1;
	m_cp =  l_base;
	m_space = l_base;
	m_kills = l_base;
	m_weight = static_cast<float>(l_base) / 2.f;
}

WingServo::WingServo( Model a_model, Armor a_armor ) : Servo( a_model, a_armor ) {
	refresh();
}

WingServo::~WingServo() {
}

void WingServo::refresh() {
	std::uint32_t l_base = get_model_num() + 1;
	m_cp =  l_base;
	m_space = l_base;
	m_kills = l_base;
	m_weight = static_cast<float>(l_base) / 2.f;
}

TailServo::TailServo( Model a_model, Armor a_armor ) : Servo( a_model, a_armor ) {
	refresh();
}

TailServo::~TailServo() {
}

void TailServo::refresh() {
	std::uint32_t l_base = get_model_num() + 1;
	m_cp =  l_base;
	m_space = l_base;
	m_kills = l_base;
	m_weight = static_cast<float>(l_base) / 2.f;
}

PodServo::PodServo( Model a_model, Armor a_armor ) : Servo( a_model, a_armor ) {
	refresh();
}

PodServo::~PodServo() {
}

void PodServo::refresh() {
	std::uint32_t l_base = get_model_num() + 1;
	m_cp =  l_base;
	m_space = l_base * 2;
	m_kills = 0;
	m_weight = 0.0f;
}

}

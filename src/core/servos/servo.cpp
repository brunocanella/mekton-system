/*
 * servo.cpp
 *
 *  Created on: May 18, 2014
 *      Author: bruno
 */

#include "servo.hpp"

namespace mekton {

Servo::Servo( Type a_type, string a_description, Model a_model, PtrArmor a_armor_ptr, uint a_extra_space_factor ) :
	m_subassemblies(*this),
	m_type(a_type),
	m_description(a_description),
	m_model(a_model),
	m_armor_ptr(a_armor_ptr),
	m_extra_space_factor(a_extra_space_factor) {
}

Servo::~Servo() {
}

bool Servo::validate() {
	return validate_armor_limit() &&
		   validate_extra_space_factor() &&
		   validate_free_space_positive();
}

void Servo::update() {
	m_weight = m_kills == 0 ? 0 : static_cast<decimal>( m_kills ) / static_cast<decimal>(2.f);

	if( m_armor_ptr != nullptr ) {
		m_armor_ptr->update();
	}

	status_invalidate();
}

bool Servo::validate_armor_limit() {
	if( m_armor_ptr == nullptr ) {
		return true;
	}
	validation_assert(
		( m_armor_ptr->model().value - m_model.value ) <= 2 &&
		"Maximum armor level can't be higher than two levels of the servo"
	);
}

bool Servo::validate_extra_space_factor() {
	validation_assert(
		m_extra_space_factor < m_kills &&
		"The extra space factor can't reduce Kills to zero or less."
	);
}

bool Servo::validate_free_space_positive() {
	validation_assert(
		free_space() > -1 &&
		"Total amount of space required by the subassemblies exceeds the Servo they are in"
	);
}

Subassemblies& Servo::subassemblies() {
	return m_subassemblies;
}

Servo::Type Servo::type() const {
	return m_type;
}

Model Servo::model() const {
	return m_model;
}

void Servo::model(const Model& a_model) {
	m_model = a_model;
	update();
}

PtrArmor Servo::armor_ptr() const {
	return m_armor_ptr;
}

void Servo::armor_ptr(const PtrArmor& a_armor_ptr) {
	m_armor_ptr = a_armor_ptr;
	update();
}

string Servo::description() const {
	return m_description;
}

void Servo::description(const string& a_description) {
	m_description = a_description;
}

uint Servo::extra_space_factor() const {
	return m_extra_space_factor;
}

void Servo::extra_space_factor(const uint& a_extra_space_factor) {
	m_extra_space_factor = a_extra_space_factor;
	update();
}

decimal Servo::cost() const {
	return m_cost;
}

decimal Servo::weight() const {
	return m_weight;
}

uint Servo::kills() const {
	return m_kills - m_extra_space_factor;
}

uint Servo::space() const {
	return m_space + m_extra_space_factor * 2;
}

decimal Servo::total_cost() const {
	return m_cost
		+ ( m_armor_ptr == nullptr ? 0 : m_armor_ptr->cost() )
		+ m_subassemblies.total_cost();
}

decimal Servo::frame_weight() const {
	return m_weight
		+ ( m_armor_ptr == nullptr ? 0 : m_armor_ptr->weight() );
}

decimal Servo::total_weight() const {
	return m_weight
		+ ( m_armor_ptr == nullptr ? 0 : m_armor_ptr->weight() )
		+ m_subassemblies.total_weight();
}

sint Servo::free_space() const {
	return space()
		- m_subassemblies.total_space();
}

} /*namespace mekton*/

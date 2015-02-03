#ifndef WEAPONMODIFIER_HPP_
#define WEAPONMODIFIER_HPP_

#include <typedefs.hpp>

#include <set>

namespace mekton {

class Weapon;

class IWeaponModifier {
public:
	IWeaponModifier( decimal a_cost_modifier );
	virtual ~IWeaponModifier() = default;

	virtual void mod( Weapon& a_this );

	virtual void unmod( Weapon& a_this );

	bool operator <( const IWeaponModifier& a_rhs ) const;
protected:
	decimal m_cost_modifier;
};

typedef std::set<IWeaponModifier> WeaponModifiers;

template<typename TType>
class WeaponModifierProduct : public IWeaponModifier {
public:
	WeaponModifierProduct(
		TType a_multiplier,
		decimal a_cost_multiplier,
		TType Weapon::*a_field_ptr
	) :
		IWeaponModifier( a_cost_multiplier ),
		m_multiplier( a_multiplier ),
		m_field_ptr( a_field_ptr ) {
	}

	virtual ~WeaponModifierProduct() = default;

	virtual void mod( Weapon& a_this ) {
		a_this.*m_field_ptr *= m_multiplier;
		IWeaponModifier::mod( a_this );
	}

	virtual void unmod( Weapon &a_this ) {
		a_this.*m_field_ptr /= m_multiplier;
		IWeaponModifier::unmod( a_this );
	}

protected:
	TType m_multiplier;
	TType Weapon::*m_field_ptr;
};

template<typename TType>
class WeaponModifierSum : public IWeaponModifier {
public:
	WeaponModifierSum(
		TType a_adder,
		decimal a_cost_multiplier,
		TType Weapon::*a_field_ptr
	) :
		IWeaponModifier( a_cost_multiplier ),
		m_adder( a_adder ),
		m_field_ptr( a_field_ptr ) {
	}

	virtual ~WeaponModifierSum() = default;

	virtual void mod( Weapon& a_this ) {
		a_this.*m_field_ptr += m_adder;
		IWeaponModifier::mod( a_this );
	}

	virtual void unmod( Weapon &a_this ) {
		a_this.*m_field_ptr -= m_adder;
		IWeaponModifier::unmod( a_this );
	}

protected:
	TType m_adder;
	TType Weapon::*m_field_ptr;
};

template<typename TType>
class WeaponModifierField : public IWeaponModifier {
public:
	WeaponModifierField(
		TType a_value,
		decimal a_cost_modifier
	) :
		IWeaponModifier(a_cost_modifier),
		m_value(a_value) {
	}
	virtual ~WeaponModifierField() = default;

	WeaponModifierField & operator= ( const TType& a_value ) {
		m_value = a_value;
		return m_value;
	}

	operator TType const & () const {
		return m_value;
	}

protected:
	TType m_value;
};

} /*namespace mekton*/

#endif // WEAPONMODIFIER_HPP_

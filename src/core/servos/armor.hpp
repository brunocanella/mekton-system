#ifndef ARMOR_HPP_
#define ARMOR_HPP_

#include <memory>
#include <typedefs.hpp>
#include "../interfaces/validatable.hpp"
#include "../frames/model.hpp"

namespace mekton {

class Armor {
public:
	Armor( Model a_model );
	virtual ~Armor() = default;

	void update();

	Model model() const;
	void model( const Model& a_model );

	decimal cp() const;

	decimal weight() const;

	std::uint32_t stopping_power() const;
protected:
	Model m_model;
	decimal m_cp;
	decimal m_weight;
	std::uint32_t m_stopping_power;
};

typedef std::shared_ptr<Armor> PtrArmor;

} /* namespace mekton */

#endif // ARMOR_HPP_

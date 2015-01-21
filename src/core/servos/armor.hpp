#ifndef ARMOR_HPP_
#define ARMOR_HPP_

namespace mekton {

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

} /* namespace mekton */

#endif // ARMOR_HPP_

#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#include <typedefs.hpp>
#include "subassembly.hpp"

namespace mekton {

class Sensor : public Subassembly
{
public:
	Sensor(
		string a_name,
		uint a_combat_range,
		uint a_communication_range,
		decimal a_cost,
		decimal a_weight,
		uint a_kills,
		uint a_space,
		string a_description = "" );
	virtual ~Sensor() = default;

	uint combat_range() const;
	void combat_range(const uint& a_combat_range);

	uint communication_range() const;
	void communication_range(const uint& a_communication_range);

protected:
	uint m_combat_range;
	uint m_communication_range;
};

} /*namespace mekton*/

#endif // SENSOR_HPP_

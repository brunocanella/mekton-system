#ifndef FOOT_HPP_
#define FOOT_HPP_

#include <typedefs.hpp>
#include <memory>
#include <vector>

namespace mekton {

class Foot
{
public:
	Foot(const Foot& a_foot) = default;
	Foot& operator=(const Foot& a_foot) = default;
	Foot(
		string a_description,
		decimal a_cost,
		uint a_space,
		uint a_damage,
		uint a_kills,
		sint a_ma_penalty
	);
	~Foot();

	string description() const;
	void description(const string& a_description);

	decimal cost() const;
	void cost(const decimal& a_cost);

	uint space() const;
	void space(const uint& a_space);

	uint damage() const;
	void damage(const uint& a_damage);

	uint kills() const;
	void kills(const uint& a_kills);

	decimal weight() const;
	void weight(const decimal& a_weight);

	sint ma_penalty() const;
	void ma_penalty(sint a_ma_penalty);

protected:
	string m_description;
	decimal m_cost;
	uint m_space;
	uint m_damage;
	uint m_kills;
	decimal m_weight;
	sint m_ma_penalty;
};

typedef std::shared_ptr<Foot> PtrFoot;

const Foot c_foot_normal = { "Foot", 0.f, 0, 2, 0, 0 };

} /*namespace mekton*/

#endif // FOOT_HPP_

#ifndef HAND_HPP
#define HAND_HPP

#include <cstdint>
#include <string>
#include <typedefs.hpp>
#include <memory>
#include <vector>

namespace mekton {

class Hand
{
public:
	Hand(const Hand& a_hand) = default;
	Hand& operator=(const Hand& a_hand) = default;
	Hand(string a_description,
		decimal a_cp,
		uint a_space,
		uint a_damage,
		uint a_kills,
		bool a_manipulation
	);
	~Hand();

	string description() const;
	void description(const string& a_description);

	decimal cp() const;
	void cp(const decimal& a_cp);

	uint space() const;
	void space(const uint& a_space);

	uint damage() const;
	void damage(const uint& a_damage);

	uint kills() const;
	void kills(const uint& a_kills);

	decimal weight() const;
	void weight(const decimal& a_weight);

	bool manipulation() const;
	void manipulation(bool a_manipulation);

protected:
	string m_description;
	decimal m_cp;
	uint m_space;
	uint m_damage;
	uint m_kills;
	decimal m_weight;
	bool m_manipulation;
};

typedef std::shared_ptr<Hand> PtrHand;

const Hand c_hand_normal = { "Hand", 2.f, 1, 1, 1, true };

} /*namespace mekton*/

#endif // HAND_HPP

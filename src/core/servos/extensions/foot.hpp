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
	Hand(
		std::string a_description,
		decimal a_cp,
		decimal a_weight,
		std::uint32_t a_space,
		std::uint32_t a_damage,
		std::uint32_t a_kills,
		bool a_manipulation
	);
	~Hand();

	std::string description() const;
	void description(const std::string& a_description);

	decimal cp() const;
	void cp(const decimal& a_cp);

	decimal weight() const;
	void weight(const decimal& a_weight);

	std::uint32_t space() const;
	void space(const std::uint32_t& a_space);

	std::uint32_t damage() const;
	void damage(const std::uint32_t& a_damage);

	std::uint32_t kills() const;
	void kills(const std::uint32_t& a_kills);

	bool manipulation() const;
	void manipulation(bool a_manipulation);

protected:
	std::string m_description;
	decimal m_cp;
	decimal m_weight;
	std::uint32_t m_space;
	std::uint32_t m_damage;
	std::uint32_t m_kills;
	bool m_manipulation;
};

typedef std::shared_ptr<Hand> PtrHand;

// ToDo: Move this to a test unit; Make it load from a database
const std::vector<Hand> g_hands = {
	{ "Hand"  , 2.f, 0.5f, 1, 1, 1, true  },
	{ "Claw"  , 4.f, 1.0f, 1, 2, 2, true  },
	{ "Talon" , 1.f, 1.0f, 1, 2, 2, false },
	{ "Pincer", 2.f, 1.5f, 1, 3, 3, false }
};

// ToDo: Move this to a test unit; Make it load from a database
const Hand & g_hand = g_hands[0];
const Hand & g_claw = g_hands[1];
const Hand & g_talon = g_hands[2];
const Hand & g_pincer = g_hands[3];

} /*namespace mekton*/

#endif // HAND_HPP

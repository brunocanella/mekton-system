#ifndef SUBASSEMBLY_HPP_
#define SUBASSEMBLY_HPP_

#include <memory>
#include "typedefs.hpp"

namespace mekton {

class Servo;

class Subassembly {
public:
	Subassembly( string a_name, decimal a_cost, decimal a_weight, uint a_kills, uint a_space, string a_description = "" );
	virtual ~Subassembly();

	string name() const;
	void name(const string& a_name);

	decimal cost() const;
	void cost(const decimal& cp);

	decimal weight() const;
	void weight(const decimal& weight);

	uint kills() const;
	void kills(const uint& kills);

	uint space() const;
	void space(const uint& space);

	string description() const;
	void description(const string& a_description);

protected:
	string m_name;
	decimal m_cost;
	decimal m_weight;
	uint m_kills;
	uint m_space;
	string m_description;
};

typedef std::shared_ptr<Subassembly> PtrSubassembly;

}

#endif // SUBASSEMBLY_HPP_

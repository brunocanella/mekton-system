#ifndef SUBASSEMBLY_HPP_
#define SUBASSEMBLY_HPP_

#include <memory>
#include "typedefs.hpp"

namespace mekton {

class Subassembly {
public:
	Subassembly( string a_name, decimal a_cost, decimal a_weight, uint a_kills, uint a_space, string a_description = "" );
	virtual ~Subassembly() = default;

	string name() const;
	void name(const string& a_name);

	string description() const;
	void description(const string& a_description);

	decimal cost() const;
	void cost(const decimal& a_cp);

	decimal weight() const;
	void weight(const decimal& a_weight);

	uint kills() const;
	void kills(const uint& a_kills);

	uint space() const;
	void space(const uint& a_space);

protected:
	string m_name;
	string m_description;
	decimal m_cost;
	decimal m_weight;
	uint m_kills;
	uint m_space;
};

typedef std::shared_ptr<Subassembly> PtrSubassembly;

}

#endif // SUBASSEMBLY_HPP_

#ifndef SUBASSEMBLIES_HPP_
#define SUBASSEMBLIES_HPP_

#include <vector>
#include <typedefs.hpp>
#include "subassembly.hpp"

namespace mekton {

class Servo;

class Subassemblies {
public:
	Subassemblies(const Servo& a_owner );
	~Subassemblies();

	void add( PtrSubassembly a_item );
	void remove( uint a_index );
	void remove( PtrSubassembly a_item );

	size_t count();

	PtrSubassembly get( int a_index );

	decimal total_cost() const;
	decimal total_weight() const;
	uint total_space() const;

	const Servo& owner() const;
protected:
	const Servo& m_owner;
	std::vector<PtrSubassembly> m_subassembly_list;
};

} /*namespace mekton*/

#endif // SUBASSEMBLIES_HPP_

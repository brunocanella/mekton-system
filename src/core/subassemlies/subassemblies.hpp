#ifndef SUBASSEMBLIES_HPP_
#define SUBASSEMBLIES_HPP_

#include <typedefs.hpp>

#include <map>

#include "subassembly.hpp"

namespace mekton {

class Servo;

typedef std::map<Subassembly*, int> SubassembliesBase;

class Subassemblies : SubassembliesBase {
public:
	using SubassembliesBase::begin;
	using SubassembliesBase::end;
	using SubassembliesBase::size;
	using SubassembliesBase::operator [];

	Subassemblies(Servo& a_owner );
	virtual ~Subassemblies();

	void alloc( Subassembly* a_ptr );
	void alloc( Subassembly* a_ptr, uint a_value );
	void dealloc( Subassembly* a_ptr );

	decimal total_cost() const;
	decimal total_weight() const;
	uint total_space() const;

	const Servo& owner() const;
protected:
	Servo& m_owner;
};

} /*namespace mekton*/

#endif // SUBASSEMBLIES_HPP_

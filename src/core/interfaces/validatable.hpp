#ifndef REFRESHABLE_HPP_
#define REFRESHABLE_HPP_

#include <cstdint>

namespace mekton {

class Refreshable {
public:
	virtual void refresh() = 0;
};

} /* namespace mekton */

#endif // REFRESHABLE_HPP_

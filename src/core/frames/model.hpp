#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <typedefs.hpp>

namespace mekton {

class Model {
public:
	uint value;
	string description;
};

typedef std::vector<Model> ModelList;

} /*namespace mekton*/

#endif // MODEL_HPP


#include "range.hpp"

namespace mekton {
namespace Weapons {
namespace Beam {

std::vector<Range> Range::hidden::data = {
	{ 0.62f, 0.25f,  "25%" },
	{ 0.75f, 0.50f,  "50%" },
	{ 0.88f, 0.75f,  "75%" },
	{ 1.00f, 1.00f, "100%" },
	{ 1.12f, 1.25f, "125%" },
	{ 1.25f, 1.50f, "150%" },
	{ 1.38f, 1.75f, "175%" },
	{ 1.50f, 2.00f, "200%" },
	{ 1.75f, 2.50f, "250%" },
	{ 2.00f, 3.00f, "300%" },
};

Range& Range::percent_25  = Range::hidden::data[0];
Range& Range::percent_50  = Range::hidden::data[1];
Range& Range::percent_75  = Range::hidden::data[2];
Range& Range::percent_100 = Range::hidden::data[3];
Range& Range::percent_125 = Range::hidden::data[4];
Range& Range::percent_150 = Range::hidden::data[5];
Range& Range::percent_175 = Range::hidden::data[6];
Range& Range::percent_200 = Range::hidden::data[7];
Range& Range::percent_250 = Range::hidden::data[8];
Range& Range::percent_300 = Range::hidden::data[9];

} /*namespace Beam*/
} /*namespace Weapons*/
} /*namespace mekton*/

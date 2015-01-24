#include "damage.hpp"

namespace mekton {
namespace Weapons {
namespace Beam {

std::vector<Damage> Damage::hidden::data = {
	{  1,  1.5f,  4 },
	{  2,  3.0f,  6 },
	{  3,  4.5f,  7 },
	{  4,  6.0f,  8 },
	{  5,  7.5f,  9 },
	{  6,  9.0f, 10 },
	{  7, 10.5f, 11 },
	{  8, 12.0f, 11 },
	{  9, 13.5f, 12 },
	{ 10, 15.0f, 13 },
	{ 11, 16.5f, 13 },
	{ 12, 18.0f, 14 },
	{ 13, 19.5f, 14 },
	{ 14, 21.0f, 15 },
	{ 15, 22.5f, 15 },
	{ 16, 24.0f, 16 },
	{ 17, 25.5f, 16 },
	{ 18, 27.0f, 17 },
	{ 19, 28.5f, 17 },
	{ 20, 30.0f, 18 },
};

Damage& Damage::kills_1  = Damage::hidden::data[0];
Damage& Damage::kills_2  = Damage::hidden::data[1];
Damage& Damage::kills_3  = Damage::hidden::data[2];
Damage& Damage::kills_4  = Damage::hidden::data[3];
Damage& Damage::kills_5  = Damage::hidden::data[4];
Damage& Damage::kills_6  = Damage::hidden::data[5];
Damage& Damage::kills_7  = Damage::hidden::data[6];
Damage& Damage::kills_8  = Damage::hidden::data[7];
Damage& Damage::kills_9  = Damage::hidden::data[8];
Damage& Damage::kills_10 = Damage::hidden::data[9];
Damage& Damage::kills_11 = Damage::hidden::data[10];
Damage& Damage::kills_12 = Damage::hidden::data[11];
Damage& Damage::kills_13 = Damage::hidden::data[12];
Damage& Damage::kills_14 = Damage::hidden::data[13];
Damage& Damage::kills_15 = Damage::hidden::data[14];
Damage& Damage::kills_16 = Damage::hidden::data[15];
Damage& Damage::kills_17 = Damage::hidden::data[16];
Damage& Damage::kills_18 = Damage::hidden::data[17];
Damage& Damage::kills_19 = Damage::hidden::data[18];
Damage& Damage::kills_20 = Damage::hidden::data[19];

} /*namespace Beam*/
} /*namespace Weapons*/
} /*namespace mekton*/


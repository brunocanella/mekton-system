#ifndef GLOBALS_HPP_
#define GLOBALS_HPP_

#include <frames/model.hpp>
#include <servos/extensions/foot.hpp>
#include <servos/extensions/hand.hpp>

namespace mekton {

namespace Models {
	namespace {
		const ModelList models = {
			{  1, "SuperLight" },
			{  2, "LightWeight" },
			{  3, "Striker" },
			{  4, "MediumStriker" },
			{  5, "HeavyStriker" },
			{  6, "MediumWeight" },
			{  7, "LightHeavy" },
			{  8, "MediumHeavy" },
			{  9, "ArmoredHeavy" },
			{ 10, "SuperHeavy" },
			{ 11, "MegaHeavy" },
		};
	}
	extern const Model & SuperLight;
	extern const Model & LightWeight;
	extern const Model & Striker;
	extern const Model & MediumStriker;
	extern const Model & HeavyStriker;
	extern const Model & MediumWeight;
	extern const Model & LightHeavy;
	extern const Model & MediumHeavy;
	extern const Model & ArmoredHeavy;
	extern const Model & SuperHeavy;
	extern const Model & MegaHeavy;
}

namespace Feet {
	namespace {
		const std::vector<Foot> feet = {
			{ "Foot"  , 0.f, 0, 2, 0,  0 },
			{ "Claw"  , 1.f, 0, 3, 1, -1 },
			{ "Talon" , 2.f, 0, 5, 3, -2 }
		};
	}
	extern const Foot & normal;
	extern const Foot & claw;
	extern const Foot & talon;
}

namespace Hands {
	namespace {
		const std::vector<Hand> hands = {
			{ "Hand"  , 2.f, 1, 1, 1, true  },
			{ "Claw"  , 4.f, 1, 2, 2, true  },
			{ "Talon" , 1.f, 1, 2, 2, false },
			{ "Pincer", 2.f, 1, 3, 3, false }
		};
	}
	extern const Hand & normal;
	extern const Hand & claw;
	extern const Hand & talon;
	extern const Hand & pincer;
}

} /*namespace mekton*/

#endif // GLOBALS_HPP_


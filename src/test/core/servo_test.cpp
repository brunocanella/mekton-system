#include "gtest/gtest.h"

#include "../globals.hpp"

#include <servos/servos.hpp>

namespace {

using namespace mekton;

TEST( Servo, Armor ) {
	Armor l_armor( Models::MediumStriker );

	ASSERT_EQ( l_armor.model().description, Models::MediumStriker.description );
	ASSERT_EQ( l_armor.cp(), 4.0  );
	ASSERT_EQ( l_armor.weight(), 2.0 );
	ASSERT_EQ( l_armor.stopping_power(), 4 );
}

TEST( Servo, ArmExtremity_Hand ) {
	Hand l_hand( "Hand", 2.f, 1, 1, 1, true );

	ASSERT_EQ( l_hand.description(), "Hand" );
	ASSERT_EQ( l_hand.cp(), 2 );
	ASSERT_EQ( l_hand.space(), 1 );
	ASSERT_EQ( l_hand.damage(), 1 );
	ASSERT_EQ( l_hand.kills(), 1 );
	ASSERT_EQ( l_hand.manipulation(), true );
	ASSERT_EQ( l_hand.weight(), 0.5 );
}

TEST( Servo, ArmExtremity_Pincer ) {
	Hand l_hand = Hands::pincer;

	ASSERT_EQ( l_hand.description(), "Pincer" );
	ASSERT_EQ( l_hand.cp(), 2 );
	ASSERT_EQ( l_hand.space(), 1 );
	ASSERT_EQ( l_hand.damage(), 3 );
	ASSERT_EQ( l_hand.kills(), 3 );
	ASSERT_EQ( l_hand.manipulation(), false );
	ASSERT_EQ( l_hand.weight(), 1.5 );
}

TEST( Servo, ArmServo_With_Hand ) {
	Arm l_arm(
		"L. Arm",
		Models::MediumStriker,
		PtrArmor(new Armor(Models::MediumStriker)),
		0,
		PtrHand(new Hand(Hands::pincer))
	);

	ASSERT_EQ( l_arm.model().description, Models::MediumStriker.description );
	ASSERT_EQ( l_arm.description(), "L. Arm" );
	ASSERT_EQ( l_arm.cp(), 5.0 );
	ASSERT_EQ( l_arm.total_cost(), 5.0 + 2.0 + 4.0 );
	ASSERT_EQ( l_arm.space(), 5 );
	ASSERT_EQ( l_arm.free_space(), 5 - 1 );
	ASSERT_EQ( l_arm.kills(), 5 );
	ASSERT_EQ( l_arm.add(), 1 );
	ASSERT_EQ( l_arm.throw_dist(), 4 );
	ASSERT_EQ( l_arm.weight(), 2.5 );
	ASSERT_EQ( l_arm.total_weight(), 2.5 + 1.5 + 2.0 );
}

TEST( Servo, ArmServo_no_hand ) {
	Arm l_arm(
		"L. Arm",
		Models::MediumStriker,
		PtrArmor(new Armor(Models::MediumStriker)),
		0,
		nullptr
	);

	ASSERT_EQ( l_arm.model().description, Models::MediumStriker.description );
	ASSERT_EQ( l_arm.description(), "L. Arm" );
	ASSERT_EQ( l_arm.cp(), 5.0 );
	ASSERT_EQ( l_arm.total_cost(), 5.0 + 4.0 );
	ASSERT_EQ( l_arm.space(), 5 );
	ASSERT_EQ( l_arm.free_space(), 5 );
	ASSERT_EQ( l_arm.kills(), 5 );
	ASSERT_EQ( l_arm.add(), 1 );
	ASSERT_EQ( l_arm.throw_dist(), 4 );
	ASSERT_EQ( l_arm.weight(), 2.5 );
	ASSERT_EQ( l_arm.total_weight(), 2.5 + 2.0 );
}

TEST( Servo, LegExtremity_foot ) {
	Foot l_foot( "Foot", 0.f, 0, 2, 0, 0 );

	ASSERT_EQ( l_foot.description(), "Foot" );
	ASSERT_EQ( l_foot.cp(), 0 );
	ASSERT_EQ( l_foot.space(), 0 );
	ASSERT_EQ( l_foot.damage(), 2 );
	ASSERT_EQ( l_foot.kills(), 0 );
	ASSERT_EQ( l_foot.weight(), 0 );
	ASSERT_EQ( l_foot.ma_penalty(), 0 );
}

TEST( Servo, LegExtremity_claw ) {
	Foot l_foot = Feet::claw;

	ASSERT_EQ( l_foot.description(), "Claw" );
	ASSERT_EQ( l_foot.cp(), 1 );
	ASSERT_EQ( l_foot.space(), 0 );
	ASSERT_EQ( l_foot.damage(), 3 );
	ASSERT_EQ( l_foot.kills(), 1 );
	ASSERT_EQ( l_foot.weight(), 0.5 );
	ASSERT_EQ( l_foot.ma_penalty(), -1 );
}

TEST( Servo, LegServo_foot ) {
	Leg l_leg(
		"L. Leg",
		Models::HeavyStriker,
		PtrArmor(new Armor(Models::MediumStriker)),
		0,
		PtrFoot(new Foot(Feet::normal))
	);

	ASSERT_EQ( l_leg.model().description, Models::HeavyStriker.description );
	ASSERT_EQ( l_leg.description(), "L. Leg" );
	ASSERT_EQ( l_leg.cp(), 6.f );
	ASSERT_EQ( l_leg.total_cost(), 6.f + 4.f );
	ASSERT_EQ( l_leg.space(), 6 );
	ASSERT_EQ( l_leg.free_space(), 6 );
	ASSERT_EQ( l_leg.kills(), 6 );
	ASSERT_EQ( l_leg.add(), 2 );
	ASSERT_EQ( l_leg.weight(), 3.f );
	ASSERT_EQ( l_leg.total_weight(), 3.f + 2.f );
}

TEST( Servo, LegServo_Talon ) {
	Leg l_leg(
		"L. Leg",
		Models::HeavyStriker,
		PtrArmor(new Armor(Models::LightWeight)),
		0,
		PtrFoot(new Foot(Feet::talon))
	);

	ASSERT_EQ( l_leg.model().description, Models::HeavyStriker.description );
	ASSERT_EQ( l_leg.description(), "L. Leg" );
	ASSERT_EQ( l_leg.cp(), 6.f );
	ASSERT_EQ( l_leg.total_cost(), 6.f + 2.f + 2.f );
	ASSERT_EQ( l_leg.space(), 6 );
	ASSERT_EQ( l_leg.free_space(), 6 );
	ASSERT_EQ( l_leg.kills(), 6 );
	ASSERT_EQ( l_leg.add(), 2 );
	ASSERT_EQ( l_leg.weight(), 3.f );
	ASSERT_EQ( l_leg.total_weight(), 3.f + 1.5f + 1.f );
	ASSERT_EQ( l_leg.foot_ptr()->description(), "Talon" );
}

TEST( Servo, Head ) {
	Head l_head( "Head", Models::Striker, PtrArmor(new Armor(Models::LightHeavy)), 1 );

	ASSERT_EQ( l_head.description(), "Head");
	ASSERT_EQ( l_head.extra_space_factor(), 1 );
	ASSERT_EQ( l_head.cp(), 3.f );
	ASSERT_EQ( l_head.total_cost(), 3.f + 7.f  );
	ASSERT_EQ( l_head.space(), 5 );
	ASSERT_EQ( l_head.free_space(), 5 );
	ASSERT_EQ( l_head.kills(), 2 );
	ASSERT_EQ( l_head.weight(), 1.5f );
	ASSERT_EQ( l_head.total_weight(), 1.5f + 3.5f );
}

TEST( Servo, Wing ) {
	Wing l_wing( "Wing", Models::MegaHeavy, PtrArmor(new Armor(Models::ArmoredHeavy)), 0 );

	ASSERT_EQ( l_wing.description(), "Wing" );
	ASSERT_EQ( l_wing.extra_space_factor(), 0 );
	ASSERT_EQ( l_wing.cp(), 11.f );
	ASSERT_EQ( l_wing.total_cost(), 11.f + 9.f );
	ASSERT_EQ( l_wing.space(), 11 );
	ASSERT_EQ( l_wing.free_space(), 11 );
	ASSERT_EQ( l_wing.kills(), 11 );
	ASSERT_EQ( l_wing.weight(), 5.5f );
	ASSERT_EQ( l_wing.total_weight(), 5.5f + 4.5f );
}

TEST( Servo, Tail ) {
	Tail l_tail( "Tail", Models::LightHeavy, PtrArmor(new Armor(Models::MediumHeavy)), 2 );

	ASSERT_EQ( l_tail.description(), "Tail" );
	ASSERT_EQ( l_tail.extra_space_factor(), 2 );
	ASSERT_EQ( l_tail.cp(), 7.f );
	ASSERT_EQ( l_tail.total_cost(), 7.f + 8.f );
	ASSERT_EQ( l_tail.space(), 11.f );
	ASSERT_EQ( l_tail.free_space(), 11.f );
	ASSERT_EQ( l_tail.kills(), 5.f );
	ASSERT_EQ( l_tail.weight(), 3.5f );
	ASSERT_EQ( l_tail.total_weight(), 3.5f + 4.0f );

	ASSERT_EQ( l_tail.validate(), true );
}

}  // namespace

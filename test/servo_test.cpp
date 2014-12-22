#include "gtest/gtest.h"

#include "servo.hpp"

namespace {

using namespace mekton;

TEST( Servo, Armor ) {
	Armor l_armor( Model::MediumStriker );

	ASSERT_EQ( l_armor.get_model(), Model::MediumStriker );
	ASSERT_EQ( l_armor.get_kills(), 0 );
	ASSERT_EQ( l_armor.get_cp(), 4.0  );
	ASSERT_EQ( l_armor.get_space(), 0 );
	ASSERT_EQ( l_armor.get_weight(), 2.0 );
	ASSERT_EQ( l_armor.get_stopping_power(), 4 );
}

TEST( Servo, ArmExtremity_Hand ) {
	ArmExtremity l_hand( "Hand", 1, true, 0, 2, 0.5, 1, 1 );

	ASSERT_EQ( l_hand.get_name(), "Hand" );
	ASSERT_EQ( l_hand.get_cp(), 2 );
	ASSERT_EQ( l_hand.get_space(), 1 );
	ASSERT_EQ( l_hand.get_damage(), 1 );
	ASSERT_EQ( l_hand.get_kills(), 1 );
	ASSERT_EQ( l_hand.is_manipulation(), true );
	ASSERT_EQ( l_hand.get_weight(), 0.5 );
	ASSERT_EQ( l_hand.get_weapom_accuracy(), 0 );
}

TEST( Servo, ArmExtremity_Pincer ) {
	ArmExtremity l_pincer( "Pincer", 3, false, 0, 2, 1.5, 3, 1 );

	ASSERT_EQ( l_pincer.get_name(), "Pincer" );
	ASSERT_EQ( l_pincer.get_cp(), 2 );
	ASSERT_EQ( l_pincer.get_space(), 1 );
	ASSERT_EQ( l_pincer.get_damage(), 3 );
	ASSERT_EQ( l_pincer.get_kills(), 3 );
	ASSERT_EQ( l_pincer.is_manipulation(), false );
	ASSERT_EQ( l_pincer.get_weight(), 1.5 );
	ASSERT_EQ( l_pincer.get_weapom_accuracy(), 0 );
}

TEST( Servo, ArmServo_hand ) {
	Armor l_armor( Model::MediumStriker );

	PtrArmExtremity lp_hand = new ArmExtremity( "Pincer", 3, true, 0, 2, 0.5, 1, 1 );

	ArmServo l_arm( Model::MediumStriker, l_armor, lp_hand );

	ASSERT_EQ( l_arm.get_model(), Model::MediumStriker );
	ASSERT_EQ( l_arm.get_cp(), 5 );
	ASSERT_EQ( l_arm.get_space(), 5 - lp_hand->get_space() );
	ASSERT_EQ( l_arm.get_kills(), 5 );
	ASSERT_EQ( l_arm.get_add(), 1 );
	ASSERT_EQ( l_arm.get_throw(), 4 );
	ASSERT_EQ( l_arm.get_weight(), 2.5 );
}

TEST( Servo, ArmServo_no_hand ) {
	Armor l_armor( Model::MediumStriker );

	ArmServo l_arm( Model::MediumStriker, l_armor, nullptr );

	ASSERT_EQ( l_arm.get_model(), Model::MediumStriker );
	ASSERT_EQ( l_arm.get_cp(), 5 );
	ASSERT_EQ( l_arm.get_space(), 5 );
	ASSERT_EQ( l_arm.get_kills(), 5 );
	ASSERT_EQ( l_arm.get_add(), 1 );
	ASSERT_EQ( l_arm.get_throw(), 4 );
	ASSERT_EQ( l_arm.get_weight(), 2.0 );
}

TEST( Servo, LegExtremity_foot ) {
	LegExtremity l_foot( "Foot", 2, 0, 0, 0, 0, 0 );

	ASSERT_EQ( l_foot.get_name(), "Foot" );
	ASSERT_EQ( l_foot.get_cp(), 0 );
	ASSERT_EQ( l_foot.get_space(), 0 );
	ASSERT_EQ( l_foot.get_damage(), 2 );
	ASSERT_EQ( l_foot.get_kills(), 0 );
	ASSERT_EQ( l_foot.get_ma_penalty(), 0 );
	ASSERT_EQ( l_foot.get_weight(), 0 );
}

TEST( Servo, LegExtremity_claw ) {
	LegExtremity l_claw( "Claw", 3, -1, 1, 0.5, 1, 0 );

	ASSERT_EQ( l_claw.get_name(), "Claw" );
	ASSERT_EQ( l_claw.get_cp(), 1 );
	ASSERT_EQ( l_claw.get_space(), 0 );
	ASSERT_EQ( l_claw.get_damage(), 3 );
	ASSERT_EQ( l_claw.get_kills(), 1 );
	ASSERT_EQ( l_claw.get_ma_penalty(), -1 );
	ASSERT_EQ( l_claw.get_weight(), 0.5 );
}

TEST( Servo, LegServo_foot ) {
	Armor l_armor( Model::MediumStriker );

	LegServo l_leg( Model::MediumStriker, l_armor );

	ASSERT_EQ( l_leg.get_cp(), 5 );
	ASSERT_EQ( l_leg.get_space(), 5 );
	ASSERT_EQ( l_leg.get_kills(), 5 );
	ASSERT_EQ( l_leg.get_add(), 1 );
	ASSERT_EQ( l_leg.get_weight(), 2.5 );
}

TEST( Servo, LegServo_Talon ) {
	Armor l_armor( Model::LightWeight );

	PtrLegExtremity lp_talon = new LegExtremity( "Talon", 5, -2, 2, 1.5, 3, 0 );

	LegServo l_leg( Model::MediumStriker, l_armor, lp_talon );
	ASSERT_EQ( l_leg.get_cp(), 5 );
	ASSERT_EQ( l_leg.get_space(), 5 );
	ASSERT_EQ( l_leg.get_kills(), 5 );
	ASSERT_EQ( l_leg.get_add(), 1 );
	ASSERT_EQ( l_leg.get_weight(), 4.0 );
	ASSERT_EQ( l_leg.get_leg_extremity()->get_name(), "Talon" );
}

TEST( Servo, Head ) {
	Armor l_armor( Model::LightHeavy );

	HeadServo l_head( Model::Striker, l_armor );

	ASSERT_EQ( l_head.get_cp(), 3 );
	ASSERT_EQ( l_head.get_space(), 3 );
	ASSERT_EQ( l_head.get_kills(), 3 );
	ASSERT_EQ( l_head.get_weight(), 1.5 );
}

TEST( Servo, Wing ) {
	Armor l_armor( Model::LightHeavy );

	WingServo l_wing( Model::Striker, l_armor );

	ASSERT_EQ( l_wing.get_cp(), 3 );
	ASSERT_EQ( l_wing.get_space(), 3 );
	ASSERT_EQ( l_wing.get_kills(), 3 );
	ASSERT_EQ( l_wing.get_weight(), 1.5 );
}

TEST( Servo, Tail ) {
	Armor l_armor( Model::LightHeavy );

	TailServo l_tail( Model::Striker, l_armor );

	ASSERT_EQ( l_tail.get_cp(), 3 );
	ASSERT_EQ( l_tail.get_space(), 3 );
	ASSERT_EQ( l_tail.get_kills(), 3 );
	ASSERT_EQ( l_tail.get_weight(), 1.5 );
}


}  // namespace

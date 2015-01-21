#include "gtest/gtest.h"

#include <globals.hpp>
#include <frames/mekton.hpp>

namespace {

using namespace mekton;

/**
 * @test Test case for the Frame described on page 57 of the Mekton Zeta book.
 */
class MektonFrameTest : public ::testing::Test {
public:
	MektonFrameTest() :
		m_frame( "Demo Frame", Models::Striker, Models::Striker ) {
		m_frame.arm_left().hand_ptr( nullptr );
		m_frame.arm_right().hand_ptr( nullptr );
	}
	~MektonFrameTest() {
	}

protected:
	Mekton m_frame;
};

TEST_F( MektonFrameTest, FrameData ) {
	ASSERT_EQ( m_frame.servos().size(), 6 );

	ASSERT_EQ( m_frame.armor_weight(), 9.f );
	ASSERT_EQ( m_frame.servo_weight(), 12.5f );

	ASSERT_EQ( m_frame.frame_weight(), 21.5f );
	ASSERT_EQ( m_frame.total_weight(), 21.5f );
}

/*
TEST_F( MechaTest, Striker ) {
	Mecha l_striker;

	auto & l_servos = l_striker.get_servos();

	Armor l_armor { Model::Striker };

	l_servos.push_back( PtrServo( new HeadServo( Model::Striker, l_armor ) ) );

	l_servos.push_back( PtrServo( new TorsoServo( Model::Striker, l_armor ) ) );

	ArmExtremity* lp_right_hand = new ArmExtremity( "Hand", 1, true, 0, 2, 0.5, 1, 1 );
	ArmExtremity* lp_left_hand = new ArmExtremity( "Hand", 1, true, 0, 2, 0.5, 1, 1 );

	l_servos.push_back( PtrServo( new ArmServo( Model::Striker, l_armor, lp_right_hand ) ) );
	l_servos.push_back( PtrServo( new ArmServo( Model::Striker, l_armor, lp_left_hand ) ) );

	l_servos.push_back( PtrServo( new LegServo( Model::Striker, l_armor ) ) );
	l_servos.push_back( PtrServo( new LegServo( Model::Striker, l_armor ) ) );

	ASSERT_EQ( l_striker.get_frame_weight(), 21.5f );
}
*/
/**
 * @test Test case for the Defense Mekton "Rapier", found in page 67 of the Mekton Z book.
 *
 * @note The frame weight and cost differs from the book, since the values for the head don't match.
 */
/*TEST_F( MechaTest, RapierMecha ) {
	Mecha l_rapier;

	Armor l_armor( Model::HeavyStriker );

	auto & l_servos = l_rapier.get_servos();

	l_servos.push_back( PtrServo( new HeadServo( Model::HeavyStriker, l_armor ) ) );

	ArmExtremity* l_right_hand = new ArmExtremity( "Hand", 1, true, 0, 2, 0.5, 1, 1 );
	ArmExtremity* l_left_hand = new ArmExtremity( "Hand", 1, true, 0, 2, 0.5, 1, 1 );

	l_servos.push_back( PtrServo( new ArmServo( Model::HeavyStriker, l_armor, l_right_hand ) ) );
	l_servos.push_back( PtrServo( new ArmServo( Model::HeavyStriker, l_armor, l_left_hand ) ) );

	l_servos.push_back( PtrServo( new LegServo( Model::LightHeavy, l_armor ) ) );
	l_servos.push_back( PtrServo( new LegServo( Model::LightHeavy, l_armor ) ) );

	PtrServo lp_torso = { new TorsoServo{ Model::MediumWeight, l_armor } };

	l_servos.push_back( lp_torso );

	l_servos.push_back( PtrServo( new PodServo( Model::MediumWeight, l_armor ) ) );

	ASSERT_EQ( l_rapier.get_frame_weight(), 40 );
	ASSERT_EQ( l_rapier.get_total_cp(), 86 );

	std::shared_ptr<Subassembly> lp_cockpit = { new Cockpit{ 1, 0, 0, 0, 1 } };

	lp_torso->subassemblies().push_back( lp_cockpit );
}
*/
}

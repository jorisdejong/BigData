/*
  ==============================================================================

	Hardcoded.cpp
	Created: 23 Mar 2017 11:20:37am
	Author:  Joris

  ==============================================================================
*/

#include "Hardcoded.h"

void Hardcoded::create()
{
	OscInputAdapter* oscInput = new OscInputAdapter( 10000 );
	OscOutputAdapter* oscOutput = new OscOutputAdapter( "127.0.0.1", 7000 );
	IoController* oscController = new IoController( "Video", oscInput, oscOutput );

	Fixture* globalFixture = new Fixture( "Global" );
	FixtureParameter* speed = new FixtureParameter( "Speed" );
	speed->addHandle( new OscControlHandle( "/layer9/video/speed/values", oscController ) );
	globalFixture->addParameter( speed );

	FixtureController::getInstance()->addFixture( globalFixture );
	FixtureController::getInstance()->addIo( oscController );
}

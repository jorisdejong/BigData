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
	FixtureController::getInstance()->addIo( oscController );

	Fixture* globalFixture = new Fixture( "Global" );
	FixtureParameter* speed = new FixtureParameter( "Speed" );
	speed->addHandle( new OscControlHandle( "/layer9/video/speed/values", oscController ) );
	globalFixture->addParameter( speed );
	FixtureController::getInstance()->addFixture( globalFixture );

	for ( int i = 0; i < 6; i++ )
	{
		Fixture* laserFixture = new Fixture( "Laser " + String( i + 1 ) );
		FixtureParameter* bright = new FixtureParameter( "Brightness" );
		bright->addHandle( new OscControlHandle( "/layer9/video/opacity/values", oscController, true ) );
		laserFixture->addParameter( bright );
		FixtureParameter* rotation = new FixtureParameter( "Rotation" );
		rotation->addHandle( new OscControlHandle( "/layer9/video/rotationz/values", oscController, true ) );
		laserFixture->addParameter( rotation );
		FixtureParameter* hue = new FixtureParameter( "Hue" );
		hue->addHandle( new OscControlHandle( "/layer9/video/effect1/param1/values", oscController ) );
		laserFixture->addParameter( hue );

		FixtureController::getInstance()->addFixture( laserFixture );
	}

	

}

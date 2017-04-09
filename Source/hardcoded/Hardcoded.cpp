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
	Fixture* globalFixture = new Fixture( "Global" );
	globalFixture->addParameter( new FixtureParameter( "Speed" ) );
	FixtureController::getInstance()->addFixture( globalFixture );

	for ( int i = 0; i < 6; i++ )
	{
		Fixture* laserFixture = new Fixture( "Laser " + String( i + 1 ) );
		laserFixture->addParameter( new FixtureParameter( "Brightness" ) );
		laserFixture->addParameter( new FixtureParameter( "Rotation" ) );
		laserFixture->addParameter( new FixtureParameter( "Hue" ) );
		FixtureController::getInstance()->addFixture( laserFixture );
	}
}

void Hardcoded::assignOsc( String outputIp, int port )
{
	OscInputAdapter* oscInput = new OscInputAdapter();
	oscInput->set( 7002 );
	OscOutputAdapter* oscOutput = new OscOutputAdapter();
	oscOutput->set( outputIp, port );
	IoController* oscController = new IoController( "Video", oscInput, oscOutput );
	FixtureController::getInstance()->addIo( oscController );

	//go through all the params and assign them
	for ( Fixture* fixture : FixtureController::getInstance()->getFixtures() )
		for ( FixtureParameter* param : fixture->getParams() )
		{
			if ( FixtureController::getInstance()->getFixtures().indexOf( fixture ) == 0 )
				param->addHandle( new OscControlHandle( "/layer9/video/speed/values", oscController ) );
			else
			{
				switch ( fixture->getParams().indexOf( param ) )
				{
				case 0:
					param->addHandle( new OscControlHandle( "/layer9/video/opacity/values", oscController, true ) );
					break;
				case 1:
					param->addHandle( new OscControlHandle( "/layer9/video/rotationz/values", oscController, true ) );
					break;
				case 2:
					param->addHandle( new OscControlHandle( "/layer9/video/effect1/param1/values", oscController ) );
					break;
				}
			}
		}
}

void Hardcoded::assignMidi()
{
	MidiInputAdapter* midiInput = new MidiInputAdapter();
	midiInput->set( 0 );
	//MidiOutputAdapter* oscOutput = new MidiOutputAdapter();
	//oscOutput->set( outputIp, port );
	IoController* midiController = new IoController( "Laser", midiInput, nullptr );
	FixtureController::getInstance()->addIo( midiController );

	//go through all the params and assign them
	for ( Fixture* fixture : FixtureController::getInstance()->getFixtures() )
		for ( FixtureParameter* param : fixture->getParams() )
		{
			if ( FixtureController::getInstance()->getFixtures().indexOf( fixture ) == 0 )
				param->addHandle( new MidiControlHandle( 1, 1, false, midiController) );
			else
			{
				switch ( fixture->getParams().indexOf( param ) )
				{
				case 0:
					param->addHandle( new MidiControlHandle( 1, 2, false, midiController, true ) );
					break;
				case 1:
					param->addHandle( new MidiControlHandle( 1, 3, false, midiController, true ) );
					break;
				case 2:
					param->addHandle( new MidiControlHandle( 1, 4, false, midiController ) );
					break;
				}
			}
		}
}

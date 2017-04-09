/*
  ==============================================================================

	MidiInputAdapter.cpp
	Created: 4 Apr 2017 11:05:41pm
	Author:  Joris

  ==============================================================================
*/

#include "MidiInputAdapter.h"
#include "../../fixture/FixtureController.h"


MidiInputAdapter::MidiInputAdapter()
{
	input = nullptr;
}

MidiInputAdapter::~MidiInputAdapter()
{
}

void MidiInputAdapter::set( int newInput )
{
	if ( input = juce::MidiInput::openDevice( newInput, this ) )
		DBG( "Opened Midi port " + MidiInput::getDevices()[newInput] );
	else
		DBG( "Could not open Midi device" );
}

void MidiInputAdapter::handleIncomingMidiMessage( juce::MidiInput *, const MidiMessage & message )
{
	FixtureController* controller = FixtureController::getInstance();
	for ( ControlHandle* handle : controller->getControlHandles() )
	{
		if ( handle->matches( message ) )
		{
			if ( message.isController() )
			{
				float value = message.getControllerValue() / 127.0f;
				if ( handle->isInverted() )
					value = 1.0f - value;
				controller->update( handle, value );
			}
		}
	}
}

Component * MidiInputAdapter::getSetupComponent()
{
	if ( !inputSetup )
	{
		inputSetup = new MidiInputSetupComponent( *this );
		inputSetup->setSize( 200, 30 );
	}
	return inputSetup;
}

int MidiInputAdapter::getIndex()
{
	if ( input )
		return MidiInput::getDevices().indexOf( input->getName() );
	else
		return -1;
}

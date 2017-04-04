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
}

MidiInputAdapter::~MidiInputAdapter()
{
}

void MidiInputAdapter::set( int newInput )
{
	if ( MidiInput::openDevice( newInput, this ) )
		DBG( "Opened Midi port " + MidiInput::getDevices()[newInput] );
	else
		DBG( "Could not open Midi device" );
}

void MidiInputAdapter::handleIncomingMidiMessage( MidiInput *, const MidiMessage & message )
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
	return nullptr;
}

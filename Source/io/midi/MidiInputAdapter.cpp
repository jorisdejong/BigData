/*
  ==============================================================================

	MidiInputAdapter.cpp
	Created: 4 Apr 2017 11:05:41pm
	Author:  Joris

  ==============================================================================
*/

#include "MidiInputAdapter.h"
#include "../../fixture/FixtureController.h"
#include "MidiControlHandle.h"


MidiInputAdapter::MidiInputAdapter()
{
	input = nullptr;
}

MidiInputAdapter::~MidiInputAdapter()
{
	if ( input )
		input->stop();
}

void MidiInputAdapter::set( int newInput )
{
	if ( input )
		input->stop();

	if ( input = juce::MidiInput::openDevice( newInput, this ) )
	{
		input->start();
		DBG( "Opened Midi port " + MidiInput::getDevices()[newInput] );
	}
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
			//at this point, we know we're a midicontrolhandle
			MidiControlHandle* midiHandle = static_cast<MidiControlHandle*>(handle);

			if ( message.isController() )
			{
				int min, max;
				midiHandle->getRange(min, max);
				int range = max - min;
				float value = (float)(message.getControllerValue() - min)/range;
				//float value = message.getControllerValue() / 127.0f;
				if ( handle->isInverted() )
					value = 1.0f - value;
				controller->update( handle, value );
			}
		}
	}
}

int MidiInputAdapter::getIndex()
{
	if ( input )
		return MidiInput::getDevices().indexOf( input->getName() );
	else
		return -1;
}

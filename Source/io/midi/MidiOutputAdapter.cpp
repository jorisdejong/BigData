/*
  ==============================================================================

	MidiOutputAdapter.cpp
	Created: 4 Apr 2017 11:05:54pm
	Author:  Joris

  ==============================================================================
*/

#include "MidiOutputAdapter.h"

MidiOutputAdapter::MidiOutputAdapter()
{
}

MidiOutputAdapter::~MidiOutputAdapter()
{
}

void MidiOutputAdapter::set( int newOutput )
{
	if ( output = MidiOutput::openDevice( newOutput ) )
		DBG( "Midi output opened to " + output->getName() );
	else
		DBG( "Could not open Midi output" );
}

void MidiOutputAdapter::sendMessage( MidiMessage m )
{
	if ( output )
		output->sendMessageNow( m );
}

Component * MidiOutputAdapter::getSetupComponent()
{
	return nullptr;
}

int MidiOutputAdapter::getIndex()
{
	if ( output )
		return MidiOutput::getDevices().indexOf( output->getName() );
	else
		return -1;
}

/*
  ==============================================================================

	MidiControlHandle.cpp
	Created: 22 Mar 2017 7:24:19pm
	Author:  Joris

  ==============================================================================
*/

#include "MidiControlHandle.h"

MidiControlHandle::MidiControlHandle( int channel, int controller, bool isNote, IoController* io, bool canBeInverted ) :
	ControlHandle( io, canBeInverted ),
	channel ( channel ),
	noteNumberOrCC ( controller ),
	isNote ( isNote )
{
}

MidiControlHandle::~MidiControlHandle()
{
}

bool MidiControlHandle::matches( const MidiMessage& m )
{
	return (m.getChannel() == channel
		&& m.isController() ? m.getControllerNumber() == noteNumberOrCC : m.isNoteOnOrOff() ? m.getNoteNumber() == noteNumberOrCC : false);
}

void MidiControlHandle::update( float value )
{
	if ( isInverted() )
		value = 1.0f - value;
	MidiMessage m;
	if ( isNote )
		m = MidiMessage::noteOn( channel, noteNumberOrCC, value * 127 );
	else
		m = MidiMessage::controllerEvent( channel, noteNumberOrCC, int(value * 127) );

	controller->getOutput()->sendMessage( m );
}

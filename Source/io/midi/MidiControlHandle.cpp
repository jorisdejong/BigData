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
	min = 0;
	max = 127;
}

MidiControlHandle::~MidiControlHandle()
{
}

bool MidiControlHandle::matches( MidiMessage m )
{
	return (m.getChannel() == channel
		&& m.isController() ? m.getControllerNumber() == noteNumberOrCC : m.isNoteOnOrOff() ? m.getNoteNumber() == noteNumberOrCC : false);
}

void MidiControlHandle::update( float value )
{
	if ( isInverted() )
		value = 1.0f - value;

	int range = max - min;
	int newValue = value * range;
	newValue += min;

	MidiMessage m;
	if ( isNote )
		m = MidiMessage::noteOn( channel, noteNumberOrCC, (uint8)newValue );
	else
	{
		m = MidiMessage::controllerEvent(channel, noteNumberOrCC, int(newValue));
		DBG("Sending Midi value " + String(newValue));
	}

	controller->getOutput()->sendMessage( m );
}

void MidiControlHandle::setRange(int newMin, int newMax)
{
	min = newMin;
	max = newMax;
}

void MidiControlHandle::getRange(int & setMin, int & setMax)
{
	setMin = min;
	setMax = max;
}

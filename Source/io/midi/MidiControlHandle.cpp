/*
  ==============================================================================

	MidiControlHandle.cpp
	Created: 22 Mar 2017 7:24:19pm
	Author:  Joris

  ==============================================================================
*/

#include "MidiControlHandle.h"

MidiControlHandle::MidiControlHandle( int channel, int controller, bool isNote )
{
}

MidiControlHandle::~MidiControlHandle()
{
}

bool MidiControlHandle::matches( const MidiMessage& m )
{
	return false;
}

/*
  ==============================================================================

    MidiControlHandle.h
    Created: 22 Mar 2017 7:24:19pm
    Author:  Joris

  ==============================================================================
*/

#ifndef MIDICONTROLHANDLE_H_INCLUDED
#define MIDICONTROLHANDLE_H_INCLUDED

#include "../ControlHandle.h"
#include "JuceHeader.h"

class MidiControlHandle :
	public ControlHandle
{
public:
	MidiControlHandle( int channel, int controller, bool isNote );
	~MidiControlHandle();

	bool matches( const MidiMessage& m );

private:
	int channel;
	int controller;
	bool isNote;

};



#endif  // MIDICONTROLHANDLE_H_INCLUDED

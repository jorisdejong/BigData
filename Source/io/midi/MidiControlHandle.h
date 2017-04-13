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
	MidiControlHandle( int channel, int controller, bool isNote, IoController* io, bool canBeInverted = false);
	~MidiControlHandle();

	bool matches( MidiMessage m ) override;
	void update( float value ) override;

	void setRange(int newMin, int newMax);
	void getRange(int& min, int& max);


private:
	int channel;
	int noteNumberOrCC;
	bool isNote;
	int min;
	int max;
};



#endif  // MIDICONTROLHANDLE_H_INCLUDED

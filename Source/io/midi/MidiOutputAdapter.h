/*
  ==============================================================================

    MidiOutputAdapter.h
    Created: 4 Apr 2017 11:05:54pm
    Author:  Joris

	Responsible for opening a midioutput and sending messages to it 

  ==============================================================================
*/

#ifndef MIDIOUTPUTADAPTER_H_INCLUDED
#define MIDIOUTPUTADAPTER_H_INCLUDED

#include "../OutputAdapter.h"

class MidiOutputAdapter : public OutputAdapter
{
public:
	MidiOutputAdapter();
	~MidiOutputAdapter();

	void set( int newOutput );
	void sendMessage( MidiMessage m ) override;

	int getIndex();

private: 
	ScopedPointer<MidiOutput> output;
};



#endif  // MIDIOUTPUTADAPTER_H_INCLUDED

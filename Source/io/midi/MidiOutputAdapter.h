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
#include "MidiOutputSetupComponent.h"

class MidiOutputAdapter : public OutputAdapter
{
public:
	MidiOutputAdapter();
	~MidiOutputAdapter();

	void set( int newOutput );
	void sendMessage( MidiMessage m ) override;

	Component* getSetupComponent() override;

	int getIndex();

private: 
	ScopedPointer<MidiOutput> output;
	ScopedPointer<MidiOutputSetupComponent> outputSetup;
};



#endif  // MIDIOUTPUTADAPTER_H_INCLUDED

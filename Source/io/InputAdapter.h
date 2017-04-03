/*
  ==============================================================================

    InputAdapter.h
    Created: 22 Mar 2017 7:03:52pm
    Author:  Joris

	InputAdapter is a virtual class to handle input messages
	like a midi or osc input
  ==============================================================================
*/

#ifndef INPUTADAPTER_H_INCLUDED
#define INPUTADAPTER_H_INCLUDED

#include "JuceHeader.h"

class InputAdapter
{
public:
	InputAdapter();
	virtual ~InputAdapter();

	virtual void set( int port );
	//virtual void set( MidiInput* input ); //midi

	virtual Component* getSetupComponent() = 0;

private:
	
};



#endif  // INPUTADAPTER_H_INCLUDED

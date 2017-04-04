/*
  ==============================================================================

    OutputAdapter.h
    Created: 22 Mar 2017 7:04:04pm
    Author:  Joris

  ==============================================================================
*/

#ifndef OUTPUTADAPTER_H_INCLUDED
#define OUTPUTADAPTER_H_INCLUDED

#include "JuceHeader.h"

class OutputAdapter
{
public:
	OutputAdapter();
	virtual ~OutputAdapter();

	virtual void sendMessage( OSCMessage m );
	virtual void sendMessage( MidiMessage m );

	virtual void set( String hostname, int port );

	virtual Component* getSetupComponent() = 0;
};



#endif  // OUTPUTADAPTER_H_INCLUDED

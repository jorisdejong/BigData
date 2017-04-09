/*
  ==============================================================================

    OscInputAdapter.h
    Created: 22 Mar 2017 8:30:22pm
    Author:  Joris

  ==============================================================================
*/

#ifndef OSCINPUTADAPTER_H_INCLUDED
#define OSCINPUTADAPTER_H_INCLUDED

#include "../InputAdapter.h"
#include "JuceHeader.h"


class OscInputAdapter :
	public InputAdapter,
	public juce::OSCReceiver,
	public juce::OSCReceiver::Listener<OSCReceiver::RealtimeCallback>
{
public:
	OscInputAdapter();
	~OscInputAdapter();

	void set( int port );

	void oscMessageReceived( const OSCMessage& message ) override;

	int getPort();

private:
	/* will return -1.0f if the message was not float or int
	otherwise it will return the first argument as float */
	float getFloatValue( const OSCMessage& m );
	int port;
};





#endif  // OSCINPUTADAPTER_H_INCLUDED

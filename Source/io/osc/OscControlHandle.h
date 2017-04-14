/*
  ==============================================================================

    OscControlHandle.h
    Created: 22 Mar 2017 8:30:01pm
    Author:  Joris

  ==============================================================================
*/

#include "../ControlHandle.h"

#ifndef OSCCONTROLHANDLE_H_INCLUDED
#define OSCCONTROLHANDLE_H_INCLUDED

#include "JuceHeader.h"

class OscControlHandle :
	public ControlHandle,
	public Timer
{
public:
	OscControlHandle( OSCAddress address, IoController* io, bool canBeInverted = false );
	~OscControlHandle();

	bool matches( OSCMessage message ) override;
	void update( float value ) override;

	void timerCallback() override;
private:
	Time lastSendTime;
	OSCAddress oscAddress;
	OSCType type;
};



#endif  // OSCCONTROLHANDLE_H_INCLUDED

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
	public ControlHandle
{
public:
	OscControlHandle( OSCAddress address );
	~OscControlHandle();

	bool matches( OSCMessage message ) override;
	void update( float value ) override;

private:
	OSCAddress oscAddress;
};



#endif  // OSCCONTROLHANDLE_H_INCLUDED

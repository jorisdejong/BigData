/*
  ==============================================================================

	ControlHandle.h
	Created: 22 Mar 2017 7:05:20pm
	Author:  Joris

	ControlHandle is a virtual class that can hold a midi, osc or other type of handle
	it keeps track of its input and output controller, so it can send and receive
	it also keeps track of which parameter it's linked to, so it can notify the fixture
  ==============================================================================
*/

#ifndef CONTROLHANDLE_H_INCLUDED
#define CONTROLHANDLE_H_INCLUDED

#include "IoController.h"
#include "JuceHeader.h"

class FixtureParameter;

class ControlHandle
{
public:
	ControlHandle( IoController* io, bool canBeInverted = false );
	virtual ~ControlHandle();

	virtual bool matches( OSCMessage m );
	virtual bool matches( MidiMessage m );

	void setParameter( FixtureParameter* newParameter );
	FixtureParameter* getParameter();

	virtual void update( float value ) = 0;

	void setLinkStatus( bool state );
	bool isLinked();

	bool canBeInverted();
	void setInverted( bool state );
	bool isInverted();

	//hacky way to determine the position of the ui for this handle
	String getControllerName();

protected:
	IoController* controller;

private:
	FixtureParameter* parameter;
	bool linked;
	bool invert;
	bool invertable;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR( ControlHandle )
};




#endif  // CONTROLHANDLE_H_INCLUDED

/*
  ==============================================================================

	OscControlHandle.cpp
	Created: 22 Mar 2017 8:30:01pm
	Author:  Joris

  ==============================================================================
*/

#include "OscControlHandle.h"

OscControlHandle::OscControlHandle( OSCAddress address ) : oscAddress( address )
{
	
}

OscControlHandle::~OscControlHandle()
{
}

bool OscControlHandle::matches( juce::OSCMessage message )
{
	return message.getAddressPattern().matches( oscAddress );
}

void OscControlHandle::update( float value )
{
	juce::OSCMessage m( oscAddress.toString(), value );
	controller->getOutput()->sendMessage( m );
}

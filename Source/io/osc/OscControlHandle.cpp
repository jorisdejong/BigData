/*
  ==============================================================================

	OscControlHandle.cpp
	Created: 22 Mar 2017 8:30:01pm
	Author:  Joris

  ==============================================================================
*/

#include "OscControlHandle.h"

OscControlHandle::OscControlHandle( OSCAddress address, IoController* io, bool canBeInverted ) :
	ControlHandle( io, canBeInverted ),
	oscAddress( address )
{
	type = juce::OSCTypes::float32;
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
	if ( isInverted() )
		value = 1.0 - value;
	juce::OSCMessage m( oscAddress.toString(), type == juce::OSCTypes::int32 ? (int) value : value );
	controller->getOutput()->sendMessage( m );
}

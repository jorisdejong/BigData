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
	//if this handle sent out less than a second, it's probably feedback
	if ( Time::getCurrentTime().getApproximateMillisecondCounter() - lastSendTime.getApproximateMillisecondCounter() < 1000 )
		return false;
	else
		return message.getAddressPattern().matches( oscAddress );
}

void OscControlHandle::update( float value )
{
	if ( isInverted() )
		value = 1.0f - value;
	juce::OSCMessage m( oscAddress.toString(), type == juce::OSCTypes::int32 ? (int) value : value );
	controller->getOutput()->sendMessage( m );
	lastSendTime = Time::getCurrentTime();
}

void OscControlHandle::timerCallback()
{
	lastSendTime = Time::getCurrentTime();
}

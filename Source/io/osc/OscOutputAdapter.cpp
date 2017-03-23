/*
  ==============================================================================

	OscOutputAdapter.cpp
	Created: 22 Mar 2017 8:30:37pm
	Author:  Joris

  ==============================================================================
*/

#include "OscOutputAdapter.h"

OscOutputAdapter::OscOutputAdapter( String hostname, int port )
{
	if ( !connect( hostname, port ) )
		DBG( "Could not create OSC output" );
}

OscOutputAdapter::~OscOutputAdapter()
{
	disconnect();
}

void OscOutputAdapter::sendMessage( OSCMessage m )
{
	String value = String( m.begin()->isFloat32() ? m.begin()->getFloat32() : m.begin()->getInt32() );
	if ( send( m ) )
		DBG( "Sent OscMessage " + m.getAddressPattern().toString() + ", value " + value );
}

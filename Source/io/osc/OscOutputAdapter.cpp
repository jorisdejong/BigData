/*
  ==============================================================================

	OscOutputAdapter.cpp
	Created: 22 Mar 2017 8:30:37pm
	Author:  Joris

  ==============================================================================
*/

#include "OscOutputAdapter.h"

OscOutputAdapter::OscOutputAdapter()
{
	ip = String();
	port = -1;
}

OscOutputAdapter::~OscOutputAdapter()
{
}

void OscOutputAdapter::set( String newHostname, int newPort )
{
	if ( !connect( newHostname, newPort ) )
		DBG( "Could not create OSC output" );
	else
	{
		DBG( "New OSC Output on " + newHostname + ", port " + String( newPort ) );
		ip = newHostname;
		port = newPort;
	}
}

void OscOutputAdapter::sendMessage( OSCMessage m )
{
	String value = String( m.begin()->isFloat32() ? m.begin()->getFloat32() : m.begin()->getInt32() );
	if ( send( m ) )
		DBG( "Sent OscMessage " + m.getAddressPattern().toString() + ", value " + value );
}

Component * OscOutputAdapter::getSetupComponent()
{
	if ( !outputSetup )
	{
		outputSetup = new OscOutputSetupComponent( *this );
		outputSetup->setSize( 200, 30 );
	}
	return outputSetup;
}

String OscOutputAdapter::getIp()
{
	return ip;
}

int OscOutputAdapter::getPort()
{
	return port;
}

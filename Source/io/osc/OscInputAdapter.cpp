/*
  ==============================================================================

	OscInputAdapter.cpp
	Created: 22 Mar 2017 8:30:22pm
	Author:  Joris

  ==============================================================================
*/

#include "OscInputAdapter.h"
#include "../../fixture/FixtureController.h"

OscInputAdapter::OscInputAdapter( int port )
{
	if ( connect( port ) )
	{
		addListener( this );
		DBG( "Started listening to OSC messages on " + String( port ) );
	}
	else
		DBG( "Could not create OSC input on port " + String( port ) );
}

OscInputAdapter::~OscInputAdapter()
{
	if ( disconnect() )
		DBG( "Stopped listening to OSC messages" );
}

void OscInputAdapter::oscMessageReceived( const OSCMessage & message )
{
	FixtureController* controller = FixtureController::getInstance();
	for ( ControlHandle* handle : controller->getControlHandles() )
	{
		if ( handle->matches( message ) )
			controller->update( handle, getFloatValue( message ) );
	}
}

float OscInputAdapter::getFloatValue( const OSCMessage & m )
{
	if ( m.begin() )
	{
		if ( m.begin()->isFloat32() )
			return m.begin()->getFloat32();
		else if ( m.begin()->isInt32() )
			return (float) m.begin()->getInt32();
	}
	return -1.0f;
}

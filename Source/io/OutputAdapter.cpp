/*
  ==============================================================================

	OutputAdapter.cpp
	Created: 22 Mar 2017 7:04:04pm
	Author:  Joris

  ==============================================================================
*/

#include "OutputAdapter.h"

OutputAdapter::OutputAdapter()
{
}

OutputAdapter::~OutputAdapter()
{
}

void OutputAdapter::sendMessage( OSCMessage m )
{
	//virtual
}

void OutputAdapter::sendMessage( MidiMessage m )
{
	//virtual
}

void OutputAdapter::set( String hostname, int port )
{
	//virtual
}

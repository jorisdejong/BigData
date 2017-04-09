/*
  ==============================================================================

	ControlHandle.cpp
	Created: 22 Mar 2017 7:05:20pm
	Author:  Joris

  ==============================================================================
*/

#include "ControlHandle.h"

ControlHandle::ControlHandle( IoController* io, bool canBeInverted ) : controller( io ), invertable( canBeInverted )
{
	linked = false;
	invert = false;
}

ControlHandle::~ControlHandle()
{

}

bool ControlHandle::matches( OSCMessage m )
{
	return false;
}

bool ControlHandle::matches( MidiMessage m )
{
	return false;
}


void ControlHandle::setParameter( FixtureParameter * newParameter )
{
	parameter = newParameter;
}

FixtureParameter * ControlHandle::getParameter()
{
	return parameter;
}

void ControlHandle::setLinkStatus( bool state )
{
	linked = state;
}

bool ControlHandle::isLinked()
{
	return linked;
}

bool ControlHandle::canBeInverted()
{
	return invertable;
}

void ControlHandle::setInverted( bool state )
{
	invert = state;
}

bool ControlHandle::isInverted()
{
	return invert;
}

String ControlHandle::getControllerName()
{
	return controller->getName();
}



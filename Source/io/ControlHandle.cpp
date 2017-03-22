/*
  ==============================================================================

    ControlHandle.cpp
    Created: 22 Mar 2017 7:05:20pm
    Author:  Joris

  ==============================================================================
*/

#include "ControlHandle.h"

ControlHandle::ControlHandle()
  {
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



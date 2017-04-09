/*
  ==============================================================================

    Hardcoded.h
    Created: 23 Mar 2017 11:20:37am
    Author:  Joris

	Hardcoded is a temporary place to add fixtures and ios
	before a gui is created for it

  ==============================================================================
*/

#ifndef HARDCODED_H_INCLUDED
#define HARDCODED_H_INCLUDED

#include "../fixture/FixtureController.h"
#include "../io/osc/OscControlHandle.h"
#include "../io/osc/OscInputAdapter.h"
#include "../io/osc/OscOutputAdapter.h"
#include "../io/midi/MidiInputAdapter.h"
#include "../io/midi/MidiOutputAdapter.h"
#include "../io/midi/MidiControlHandle.h"

class Hardcoded
{
public:
	static void create();
	static void assignOsc( String outputIp, int port );
	static void assignMidi();

};



#endif  // HARDCODED_H_INCLUDED

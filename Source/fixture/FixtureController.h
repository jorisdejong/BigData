/*
  ==============================================================================

	FixtureController.h
	Created: 22 Mar 2017 7:04:53pm
	Author:  Joris

	FixtureController is the boss of the bunch
	it keeps track of all the fixtures and their params
	and checks any incoming messages against the list of assigned handles
	then it keeps a list of parameters that need to notify their ios of changers
  ==============================================================================
*/

#ifndef FIXTURECONTROLLER_H_INCLUDED
#define FIXTURECONTROLLER_H_INCLUDED

#include <map>

#include "JuceHeader.h"
#include "Fixture.h"
#include "../io/ControlHandle.h"

class FixtureController
{
public:
	FixtureController();
	~FixtureController();

	static FixtureController* getInstance();
	static void destroyInstance();

	void addFixture( Fixture* newFixture );
	
	void addIo( IoController* newController );

	const Array<ControlHandle*> getControlHandles();
	const OwnedArray<Fixture>& getFixtures();

	void update( ControlHandle* handle, float value );
	void process();

private:
	static FixtureController* instance;
	OwnedArray<Fixture> fixtures;
	OwnedArray<IoController> ioControllers;
	CriticalSection lock;
	std::map<ControlHandle*, float> updatedHandles;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR( FixtureController )
};




#endif  // FIXTURECONTROLLER_H_INCLUDED

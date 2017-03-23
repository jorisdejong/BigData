/*
  ==============================================================================

	FixtureController.cpp
	Created: 22 Mar 2017 7:04:53pm
	Author:  Joris

  ==============================================================================
*/

#include "FixtureController.h"

FixtureController* FixtureController::instance = nullptr;

FixtureController::FixtureController()
{
}

FixtureController::~FixtureController()
{
}

FixtureController * FixtureController::getInstance()
{
	if ( instance == nullptr )
		instance = new FixtureController();

	return instance;
}

void FixtureController::destroyInstance()
{
	delete instance;
	instance = nullptr;
}

void FixtureController::addFixture( Fixture * newFixture )
{
	fixtures.add( newFixture );
}

void FixtureController::addIo( IoController * newController )
{
	ioControllers.add( newController );
}

const Array<ControlHandle*> FixtureController::getControlHandles()
{
	Array<ControlHandle*> handles;

	for ( Fixture* fixture : fixtures )
	{
		for ( auto param : fixture->getParams() )
		{
			for ( auto handle : param->getHandles() )
			{
				handles.add( handle );
			}
		}
	}

	return handles;
}

void FixtureController::update( ControlHandle* handle, float value )
{
	const ScopedLock lockHere( lock );
	updatedHandles[handle] = value;
}

void FixtureController::process()
{
	const ScopedLock lockHere( lock );
	for ( auto handle : updatedHandles )
		handle.first->getParameter()->update( handle.second, handle.first );
	
	updatedHandles.clear();
}

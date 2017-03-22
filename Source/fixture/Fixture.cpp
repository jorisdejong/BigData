/*
  ==============================================================================

    VirtualFixture.cpp
    Created: 22 Mar 2017 7:02:08pm
    Author:  Joris

  ==============================================================================
*/

#include "Fixture.h"

Fixture::Fixture()
  {
  }

Fixture::~Fixture()
{
}

void Fixture::addParameter( FixtureParameter * newParam )
{
	params.add( newParam );
}

const OwnedArray<FixtureParameter>& Fixture::getParams()
{
	return params;
}

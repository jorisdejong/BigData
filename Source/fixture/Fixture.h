/*
  ==============================================================================

	Fixture.h
    Created: 22 Mar 2017 7:02:08pm
    Author:  Joris

	Fixture is a simple object with parameters
	it keeps track of a list of IOs
	each IOs can be linked to a parameter
	and be notified of changes to the parameter
  ==============================================================================
*/

#ifndef FIXTURE_H_INCLUDED
#define FIXTURE_H_INCLUDED

#include "JuceHeader.h"
#include "FixtureParameter.h"

class Fixture
{
public:
	Fixture();
	~Fixture();

	void addParameter( FixtureParameter* newParam );
	const OwnedArray<FixtureParameter>& getParams();

private:
	OwnedArray<FixtureParameter> params;

};


#endif  // VIRTUALFIXTURE_H_INCLUDED

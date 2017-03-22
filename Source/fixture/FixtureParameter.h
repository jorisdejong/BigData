/*
  ==============================================================================

   FixtureParameter.h
	Created: 22 Mar 2017 7:12:47pm
	Author:  Joris

	A fixtureparameter is a single variable
	that can be controlled by multiple IOs
	It keeps track of the various IOs it's linked to
	and updates them when necessarry
  ==============================================================================
*/

#ifndef FIXTUREPARAMETER_H_INCLUDED
#define FIXTUREPARAMETER_H_INCLUDED

#include "JuceHeader.h"
#include "../io/ControlHandle.h"

class FixtureParameter
{
public:
	FixtureParameter();
	~FixtureParameter();

	void update( float value, ControlHandle* source );

	void addHandle( ControlHandle* newHandle );
	const OwnedArray<ControlHandle>& getHandles();

	juce::Uuid uniqueId;

private:
	OwnedArray<ControlHandle> handles;
	
};

const bool operator< ( const FixtureParameter& lhs, const FixtureParameter& rhs );






#endif  // FIXTUREPARAMETER_H_INCLUDED

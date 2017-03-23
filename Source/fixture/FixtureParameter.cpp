/*
  ==============================================================================

	FixtureParameter.cpp
	Created: 22 Mar 2017 7:12:47pm
	Author:  Joris

  ==============================================================================
*/

#include "FixtureParameter.h"



FixtureParameter::FixtureParameter( String name ) : name ( name )
{
	uniqueId = juce::Uuid();
}

FixtureParameter::~FixtureParameter()
{
	handles.clear();
}

void FixtureParameter::update( float newValue, ControlHandle* source )
{
	for ( ControlHandle* handle : handles )
		//if ( handle != source ) //no feedback
			handle->update( newValue );
}

void FixtureParameter::addHandle( ControlHandle * newHandle )
{
	//parameter and handle need to know each other
	newHandle->setParameter( this );
	handles.add( newHandle );
}

const OwnedArray<ControlHandle>& FixtureParameter::getHandles()
{
	return handles;
}

const bool operator<( const FixtureParameter& lhs, const FixtureParameter& rhs )
{
	return (lhs.uniqueId.getRawData() < rhs.uniqueId.getRawData());
}
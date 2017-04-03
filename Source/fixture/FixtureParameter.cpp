/*
  ==============================================================================

	FixtureParameter.cpp
	Created: 22 Mar 2017 7:12:47pm
	Author:  Joris

  ==============================================================================
*/

#include "FixtureParameter.h"



FixtureParameter::FixtureParameter( String name ) : name( name )
{
	uniqueId = juce::Uuid();
	slider = nullptr;
}

FixtureParameter::~FixtureParameter()
{
	handles.clear();
}

void FixtureParameter::update( float newValue, ControlHandle* source )
{
	for ( ControlHandle* handle : handles )
		if ( handle != source ) //no feedback
			if ( handle->isLinked() )
				handle->update( newValue );
	if ( slider )
		slider->update( newValue );
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

String FixtureParameter::getName()
{
	return name;
}

void FixtureParameter::setSlider( ParamSlider * newSlider )
{
	slider = newSlider;
}

const bool operator<( const FixtureParameter& lhs, const FixtureParameter& rhs )
{
	return (lhs.uniqueId.getRawData() < rhs.uniqueId.getRawData());
}
/*
  ==============================================================================

	FixtureParameter.cpp
	Created: 22 Mar 2017 7:12:47pm
	Author:  Joris

  ==============================================================================
*/

#include "FixtureParameter.h"
#include "../gui/ParamBlock.h"


FixtureParameter::FixtureParameter( String name ) : name( name )
{
	uniqueId = juce::Uuid();
	block = nullptr;
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
	
	if ( block )
		block->getSlider()->update( newValue );
}

void FixtureParameter::sliderValueChanged(Slider * slider)
{
	for (ControlHandle* handle : handles)
		if (handle->isLinked())
			handle->update((float)slider->getValue());

	if (block)
		block->getSlider()->update((float)slider->getValue());
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

void FixtureParameter::setParamBlock( ParamBlock * newBlock )
{
	block = newBlock;
	block->getSlider()->addListener(this);
}

const bool operator<( const FixtureParameter& lhs, const FixtureParameter& rhs )
{
	return (lhs.uniqueId.getRawData() < rhs.uniqueId.getRawData());
}
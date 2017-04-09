/*
  ==============================================================================

    FixtureBlock.cpp
    Created: 9 Apr 2017 11:55:42am
    Author:  Joris

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "FixtureBlock.h"



//==============================================================================
FixtureBlock::FixtureBlock( Fixture* fixture) : fixture (fixture)
{
	fixtureLabel = new Label( fixture->getName(), fixture->getName() );
	addAndMakeVisible( fixtureLabel );
	fixtureLabel->setColour( Label::textColourId, Colours::white );
	fixtureLabel->setFont( Font( "Impact", 24.0f, Font::plain ) );
	fixtureLabel->setJustificationType( Justification::centred );

	for ( FixtureParameter* param : fixture->getParams() )
	{
		ParamBlock* block = new ParamBlock( param );
		paramBlocks.add( block );
		addAndMakeVisible( block );
	}
}

FixtureBlock::~FixtureBlock()
{
}

void FixtureBlock::paint (Graphics& )
{
  
}

void FixtureBlock::resized()
{
	float h = 1.0f / (fixture->getParams().size() + 1);
	fixtureLabel->setBoundsRelative( 0.0f, 0.0f, 1.0f, h );
	fixtureLabel->setCentreRelative( 0.5, 0.1f );

	float y = h;
	for ( auto block : paramBlocks )
	{
		block->setBoundsRelative( 0.0f, y, 1.0f, h );
		y += h;
	}
}

float FixtureBlock::getRelativeHeight()
{
	FixtureController* controller = FixtureController::getInstance();
	int totalParamCount = 0;
	for ( auto fixtureIt : controller->getFixtures() )
		totalParamCount += fixtureIt->getParams().size();
	return (float) fixture->getParams().size() / totalParamCount;
}

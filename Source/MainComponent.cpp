/*
  ==============================================================================

	This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "fixture/FixtureController.h"
#include "gui/HandleBlock.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
	setSize( 600, 1400 );

	float y = 0.05f;
	//create items for each fixtureparam
	for ( Fixture* fixture : FixtureController::getInstance()->getFixtures() )
	{
		Label* label = new Label( fixture->getName(), fixture->getName() );
		addAndMakeVisible( label );
		label->setColour( Label::textColourId, Colours::white );
		label->setFont( label->getFont().withHeight( 32.0f ) );
		label->setJustificationType( Justification::centred );
		label->setSize( 100, 40 );
		label->setCentreRelative( 0.5f, y );

		y += 0.04f;
		for ( FixtureParameter* param : fixture->getParams() )
		{
			label = new Label( param->getName(), param->getName() );
			addAndMakeVisible( label );
			label->setColour( Label::textColourId, Colours::white );
			label->setJustificationType( Justification::centred );
			label->setSize( 100, 40 );
			label->setCentreRelative( 0.5f, y );

			for ( ControlHandle* handle : param->getHandles() )
			{
				HandleBlock* block = new HandleBlock( handle );
				addAndMakeVisible( block );
				block->setSize( 100, 40 );
				if ( handle->getControllerName() == "Video" )
					block->setCentreRelative( 0.25f, y );
				else
					block->setCentreRelative( 0.75f, y );
			}
			y += 0.03f;
		}
	}
}

MainContentComponent::~MainContentComponent()
{

}

void MainContentComponent::paint( Graphics& g )
{
	g.fillAll( Colour( 0xff001F36 ) );
}

void MainContentComponent::resized()
{
	// This is called when the MainContentComponent is resized.
	// If you add any child components, this is where you should
	// update their positions.
}

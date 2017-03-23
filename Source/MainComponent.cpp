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
	lookAndFeel = new BigDataLookAndFeel();
	setLookAndFeel( lookAndFeel );
	setSize( 600, 1200 );

	float y = 0.04f;
	//create items for each fixtureparam
	for ( Fixture* fixture : FixtureController::getInstance()->getFixtures() )
	{
		y += 0.01f;

		Label* fixtureLabel = new Label( fixture->getName(), fixture->getName() );
		addAndMakeVisible( fixtureLabel );
		fixtureLabel->setColour( Label::textColourId, Colours::white );
		fixtureLabel->setFont( Font("Impact", 35.0f, Font::plain ));
		fixtureLabel->setJustificationType( Justification::centred );
		fixtureLabel->setSize( 100, 40 );
		fixtureLabel->setCentreRelative( 0.5f, y );
		components.add( fixtureLabel );

		y += 0.03f;

		for ( FixtureParameter* param : fixture->getParams() )
		{
			/*Label* paramLabel = new Label( param->getName(), param->getName() );
			addAndMakeVisible( paramLabel );
			paramLabel->setColour( Label::textColourId, Colours::white );
			paramLabel->setJustificationType( Justification::centred );
			paramLabel->setSize( 100, 40 );
			paramLabel->setCentreRelative( 0.5f, y );
			components.add( paramLabel );*/
			ParamSlider* slider = new ParamSlider( param->getName() );
			addAndMakeVisible( slider );
			slider->setSize( 120, 40 );
			slider->setCentreRelative( 0.5f, y );
			components.add( slider );
			param->setSlider( slider );

			for ( ControlHandle* handle : param->getHandles() )
			{
				HandleBlock* block = new HandleBlock( handle );
				addAndMakeVisible( block );
				block->setSize( 100, 40 );
				if ( handle->getControllerName() == "Video" )
					block->setCentreRelative( 0.25f, y );
				else
					block->setCentreRelative( 0.75f, y );
				components.add( block );
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
	
}

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
	setSize( 300, 600 );

	int w = getWidth();
	float h = (float) getHeight();

	float y = 48 / h;
	//create items for each fixtureparam
	for ( Fixture* fixture : FixtureController::getInstance()->getFixtures() )
	{
		y += 12 / h;
		int ch = int( 0.03f * h );

		Label* fixtureLabel = new Label( fixture->getName(), fixture->getName() );
		addAndMakeVisible( fixtureLabel );
		fixtureLabel->setColour( Label::textColourId, Colours::white );
		fixtureLabel->setFont( Font( "Impact", 0.03f * h, Font::plain ) );
		fixtureLabel->setJustificationType( Justification::centred );
		fixtureLabel->setSize( int( 0.16667 * w ), ch );
		fixtureLabel->setCentreRelative( 0.5f, y );
		components.add( fixtureLabel );

		y += (ch * 0.9f) / h;

		for ( FixtureParameter* param : fixture->getParams() )
		{
			ParamSlider* slider = new ParamSlider( param->getName() );
			addAndMakeVisible( slider );
			slider->setSize( int( 0.2 * w ), ch );
			slider->setCentreRelative( 0.5f, y );
			components.add( slider );
			param->setSlider( slider );

			for ( ControlHandle* handle : param->getHandles() )
			{
				HandleBlock* block = new HandleBlock( handle );
				addAndMakeVisible( block );
				block->setSize( int( 0.16667 * w ), ch );
				if ( handle->getControllerName() == "Video" )
					block->setCentreRelative( 0.25f, y );
				else
					block->setCentreRelative( 0.75f, y );
				components.add( block );
			}
			y += (ch * 0.9f) / h;
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

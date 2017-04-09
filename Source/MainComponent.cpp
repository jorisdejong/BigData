/*
  ==============================================================================

	This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "fixture/FixtureController.h"



//==============================================================================
MainContentComponent::MainContentComponent()
{
	lookAndFeel = new BigDataLookAndFeel();
	setLookAndFeel( lookAndFeel );
	
	//create items for each fixtureparam
	for ( Fixture* fixture : FixtureController::getInstance()->getFixtures() )
	{
		FixtureBlock* fixtureBlock = new FixtureBlock( fixture );
		fixtureBlocks.add( fixtureBlock );
		addAndMakeVisible( fixtureBlock );
	}

	//add setup buttons
	setup = new TextButton( "Setup" );
	addAndMakeVisible( setup );
	setup->addListener( this );

	setSize( 600, 300 );
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
	float y = 0.0f;
	for ( FixtureBlock* fixtureBlock : fixtureBlocks )
	{
		float h = fixtureBlock->getRelativeHeight();
		fixtureBlock->setBoundsRelative( 0.16666f, y, 0.66f, h );
		y += h;
	}

	setup->setBoundsRelative( 0.9f, 0.9f, 0.1f, 0.1f );
}

void MainContentComponent::buttonClicked( Button * )
{
	for ( IoController* controller : FixtureController::getInstance()->getControllers() )
		controller->toggleSetupComponent();
}

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
	lookAndFeel->setColour( TextButton::buttonColourId, Colours::grey.withMultipliedBrightness( 0.1f ) );
	lookAndFeel->setColour( TextButton::buttonOnColourId, Colours::red );
	setLookAndFeel( lookAndFeel );
	
	//create items for each fixtureparam
	for ( Fixture* fixture : FixtureController::getInstance()->getFixtures() )
	{
		FixtureBlock* fixtureBlock = new FixtureBlock( fixture );
		fixtureBlocks.add( fixtureBlock );
		addAndMakeVisible( fixtureBlock );
	}

	linkAllVideo = new TextButton( "Link All" );
	linkAllVideo->addListener( this );
	linkAllVideo->setClickingTogglesState( true );
	addAndMakeVisible( linkAllVideo );

	linkAllLaser = new TextButton( "Link All" );
	linkAllLaser->addListener( this );
	linkAllLaser->setClickingTogglesState( true );
	addAndMakeVisible( linkAllLaser );

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
		fixtureBlock->setBoundsRelative( 0.16666f, y, 0.66f, h - 0.001f );
		y += h;
	}

	linkAllVideo->setBoundsRelative( 0.05f, 0.0f, 0.1f, 0.1f );
	linkAllLaser->setBoundsRelative( 0.85f, 0.0f, 0.1f, 0.1f );
}

void MainContentComponent::buttonClicked( Button * b )
{
		for ( auto fixtureBlock : fixtureBlocks )
			for ( auto paramBlock : fixtureBlock->getParamBlocks() )
				for ( HandleBlock* block : paramBlock->getBlocks() )
					if ( (paramBlock->getBlocks().indexOf( block ) == 0 || paramBlock->getBlocks().indexOf( block ) == 2 ) && b == linkAllVideo )
						block->link();
					else if ( paramBlock->getBlocks().indexOf( block ) == 1 && b == linkAllLaser )
						block->link();

}

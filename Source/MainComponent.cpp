/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
	OscInputAdapter* oscInput = new OscInputAdapter( 10000 );
	OscOutputAdapter* oscOutput = new OscOutputAdapter( "127.0.0.1", 7000 );
	

	oscController = new IoController( oscInput, oscOutput );

	Fixture* globalFixture = new Fixture( "Global" );
	FixtureParameter* speed = new FixtureParameter( "Speed" );
	ControlHandle* oscHandle = new OscControlHandle( "/layer9/video/speed/values" );
	oscHandle->setIoController( oscController );
	speed->addHandle( oscHandle );
	globalFixture->addParameter( speed );
	FixtureController::getInstance()->addFixture( globalFixture );

	//start running the timer that will process the incoming commands
	startTimerHz( 60 );
	
    setSize (600, 400);
}

MainContentComponent::~MainContentComponent()
{
	oscController = nullptr;
	FixtureController::destroyInstance();
}

void MainContentComponent::timerCallback()
{
	FixtureController::getInstance()->process();
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

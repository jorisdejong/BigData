/*
  ==============================================================================

	IoController.cpp
	Created: 22 Mar 2017 7:03:21pm
	Author:  Joris

  ==============================================================================
*/

#include "IoController.h"
#include "../fixture/FixtureController.h"

IoController::IoController( String name, InputAdapter* input, OutputAdapter* output ) : name( name ), input( input ), output( output )
{
}

IoController::~IoController()
{
	input = nullptr;
	output = nullptr;
}

InputAdapter* IoController::getInput()
{
	return input;
}

OutputAdapter* IoController::getOutput()
{
	return output;
}

String IoController::getName()
{
	return name;
}

void IoController::toggleSetupComponent()
{
	if ( !setup )
	{
		setup = new juce::Component();
		int w = 0;
		int h = 0;
		if ( input )
		{
			juce::Component* inputSetup = input->getSetupComponent();
			setup->addAndMakeVisible( inputSetup );
			inputSetup->setTopLeftPosition( 0, h );
			w = inputSetup->getWidth();
			h = inputSetup->getHeight();
		}
		if ( output )
		{
			juce::Component* outputSetup = output->getSetupComponent();
			setup->addAndMakeVisible( outputSetup );
			outputSetup->setTopLeftPosition( 0, h );
			w = outputSetup->getWidth();
			h += outputSetup->getHeight();
		}

		if ( !input && !output )
			return;

		setup->setSize( w, h );

		TopLevelWindow::getActiveTopLevelWindow()->getChildComponent( 0 )->addChildComponent( setup );
		
		setup->setCentreRelative( 0.85f, 0.7f + FixtureController::getInstance()->getControllers().indexOf( this ) * 0.1f );
	}

	setup->setVisible( !setup->isVisible() );
}

/*
  ==============================================================================

	IoController.cpp
	Created: 22 Mar 2017 7:03:21pm
	Author:  Joris

  ==============================================================================
*/

#include "IoController.h"

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
		//this is dodgy as fuck
		float hc = 0.5f;
		if ( TopLevelWindow::getActiveTopLevelWindow()->getChildComponent( 0 )->getNumChildComponents() > 1 )
			hc += (float)TopLevelWindow::getActiveTopLevelWindow()->getChildComponent( 0 )->getChildComponent(0)->getHeight() / (float)TopLevelWindow::getActiveTopLevelWindow()->getChildComponent( 0 )->getHeight();
		setup->setCentreRelative( 0.5f, hc );
	}

	setup->setVisible( !setup->isVisible() );
}

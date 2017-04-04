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
		setup = new Component();
		if ( input )
		{
			Component* inputSetup = input->getSetupComponent();
			setup->addAndMakeVisible( inputSetup );
			inputSetup->setTopLeftPosition( 0, 0 );

			setup->setSize( inputSetup->getBounds().getWidth(), inputSetup->getBounds().getHeight() );
		}
		TopLevelWindow::getActiveTopLevelWindow()->getChildComponent( 0 )->addChildComponent( setup );
		setup->setCentreRelative( 0.5f, 0.5f );
	}

	setup->setVisible( !setup->isVisible() );
}

/*
  ==============================================================================

    HandleBlock.cpp
    Created: 23 Mar 2017 12:14:23pm
    Author:  Joris

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "HandleBlock.h"

//==============================================================================
HandleBlock::HandleBlock( ControlHandle* handle, bool isFlipped ) : handle( handle ), isFlipped ( isFlipped )
{
	linkButton = new TextButton( "Link" );
	linkButton->addListener( this );
	linkButton->setClickingTogglesState( true );
	
	addAndMakeVisible( linkButton );

	invertButton = new TextButton( "I" );
	invertButton->addListener( this );
	invertButton->setClickingTogglesState( true );
	if ( handle->canBeInverted() )
		addAndMakeVisible( invertButton );
}

HandleBlock::~HandleBlock()
{
}

void HandleBlock::paint (Graphics& )
{
 
}

void HandleBlock::resized()
{
	if ( isFlipped )
	{
		invertButton->setBoundsRelative( 0.0f, 0.0f, 0.5f, 1.0f );
		linkButton->setBoundsRelative( 0.5f, 0.0f, 0.5f, 1.0f );
	}
	else
	{
		linkButton->setBoundsRelative( 0.0f, 0.0f, 0.5f, 1.0f );
		invertButton->setBoundsRelative( 0.5f, 0.0f, 0.5f, 1.0f );
	}
}

void HandleBlock::buttonClicked( Button * b )
{
	if ( b == linkButton )
		handle->setLinkStatus( b->getToggleState() );
	else if ( b == invertButton )
		handle->setInverted( b->getToggleState() );
}

void HandleBlock::link()
{
	linkButton->triggerClick();
}

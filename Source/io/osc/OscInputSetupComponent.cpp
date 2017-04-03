/*
  ==============================================================================

	OscInputSetupComponent.cpp
	Created: 3 Apr 2017 10:51:56pm
	Author:  Joris

  ==============================================================================
*/

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "OscInputSetupComponent.h"
#include "OscInputAdapter.h"

//==============================================================================
OscInputSetupComponent::OscInputSetupComponent( OscInputAdapter& adapter ) : adapter( adapter )
{
	label = new Label( "label", "Input Port:" );
	addAndMakeVisible( label );
	editor = new TextEditor();
	editor->setInputRestrictions( 0, "0123456789" );
	editor->addListener( this );
	addAndMakeVisible( editor );
}

OscInputSetupComponent::~OscInputSetupComponent()
{
}

void OscInputSetupComponent::textEditorReturnKeyPressed( TextEditor &t )
{
	updatePort( t.getText().getIntValue() );
}

void OscInputSetupComponent::textEditorEscapeKeyPressed( TextEditor & )
{
	editor->setText( String( adapter.getPort() ) );
}

void OscInputSetupComponent::textEditorFocusLost( TextEditor &t )
{
	updatePort( t.getText().getIntValue() );
}

void OscInputSetupComponent::paint( Graphics& g )
{
	g.setColour( Colours::grey );
	g.drawRect( getLocalBounds(), 1 );   // draw an outline around the component

	g.setColour( Colours::lightblue );
	g.setFont( 14.0f );
	g.drawText( "OscInputSetupComponent", getLocalBounds(),
		Justification::centred, true );   // draw some placeholder text
}

void OscInputSetupComponent::resized()
{
	label->setBoundsRelative( 0.0f, 0.0f, 0.25f, 1.0f );
	editor->setBoundsRelative( 0.25f, 0.0f, 0.75f, 1.0f );
	editor->setText( String( adapter.getPort() ) );
}

void OscInputSetupComponent::updatePort( int port )
{
	adapter.set( port );
	//this will set the text correctly regardless whether the set was succesful
	//because the port number will not have updated
	editor->setText( String( adapter.getPort() ) );
	
}

/*
  ==============================================================================

    OscOutputSetupComponent.cpp
    Created: 4 Apr 2017 9:49:55pm
    Author:  Joris

  ==============================================================================
*/

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "OscOutputSetupComponent.h"
#include "OscOutputAdapter.h"

//==============================================================================
OscOutputSetupComponent::OscOutputSetupComponent( OscOutputAdapter& adapter ) : adapter ( adapter )
{
	label = new Label( "label", "Out:" );
	addAndMakeVisible( label );
	label->setColour( Label::ColourIds::textColourId, Colours::whitesmoke );

	ipEditor = new TextEditor();
	ipEditor->setInputRestrictions( 0, "0123456789." );
	ipEditor->addListener( this );
	addAndMakeVisible( ipEditor );

	portEditor = new TextEditor();
	portEditor->setInputRestrictions( 0, "0123456789" );
	portEditor->addListener( this );
	addAndMakeVisible( portEditor );
}

OscOutputSetupComponent::~OscOutputSetupComponent()
{
}

void OscOutputSetupComponent::textEditorReturnKeyPressed( TextEditor & )
{
	adapter.set( ipEditor->getText(), portEditor->getText().getIntValue() );
	ipEditor->setText( adapter.getIp() );
	portEditor->setText( String( adapter.getPort() ) );
}

void OscOutputSetupComponent::textEditorEscapeKeyPressed( TextEditor &t )
{
	if ( &t == ipEditor )
		ipEditor->setText( adapter.getIp() );
	if ( &t == portEditor )
		portEditor->setText( String( adapter.getPort() ));
}

void OscOutputSetupComponent::textEditorFocusLost( TextEditor & )
{
	adapter.set( ipEditor->getText(), portEditor->getText().getIntValue() );
	ipEditor->setText( adapter.getIp() );
	portEditor->setText( String( adapter.getPort() ) );
}

void OscOutputSetupComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
}

void OscOutputSetupComponent::resized()
{
	label->setBoundsRelative( 0.0f, 0.0f, 0.25f, 1.0f );
	ipEditor->setBoundsRelative( 0.25f, 0.0f, 0.5f, 1.0f );
	portEditor->setBoundsRelative( 0.75f, 0.0f, 0.25f, 1.0f );
	ipEditor->setText( adapter.getIp() );
	portEditor->setText( String( adapter.getPort() ) );
}

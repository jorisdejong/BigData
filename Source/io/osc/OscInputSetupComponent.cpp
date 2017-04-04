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
	label = new Label( "label", "In:" );
	addAndMakeVisible( label );
	label->setColour( Label::ColourIds::textColourId, Colours::whitesmoke );

	//ipaddresses
	Array<IPAddress> ips;
	IPAddress::findAllAddresses( ips );

	if ( ips.size() > 1 )
	{
		ip = new Label( "ip", ips[1].toString() );
		addAndMakeVisible( ip );
		ip->setColour( Label::ColourIds::textColourId, Colours::whitesmoke );
	}

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
	g.fillAll( Colours::black );
	g.setColour( Colours::grey );
	g.drawRect( getLocalBounds(), 1 );   // draw an outline around the component
}

void OscInputSetupComponent::resized()
{
	label->setBoundsRelative( 0.0f, 0.0f, 0.25f, 1.0f );
	if ( ip )
		ip->setBoundsRelative( 0.25f, 0.0f, 0.5f, 1.0f );
	editor->setBoundsRelative( 0.75f, 0.0f, 0.25f, 1.0f );
	editor->setText( String( adapter.getPort() ) );
}

void OscInputSetupComponent::updatePort( int port )
{
	adapter.set( port );
	//this will set the text correctly regardless whether the set was succesful
	//because the port number will not have updated
	editor->setText( String( adapter.getPort() ) );
	
}

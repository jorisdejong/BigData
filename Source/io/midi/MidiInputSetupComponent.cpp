/*
  ==============================================================================

	MidiInputSetupComponent.cpp
	Created: 9 Apr 2017 12:59:14pm
	Author:  Joris

  ==============================================================================
*/

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "MidiInputSetupComponent.h"
#include "MidiInputAdapter.h"

//==============================================================================
MidiInputSetupComponent::MidiInputSetupComponent( MidiInputAdapter& adapter ) : adapter( adapter )
{
	label = new Label( "label", "In:" );
	addAndMakeVisible( label );
	label->setColour( Label::ColourIds::textColourId, Colours::whitesmoke );

	comboBox = new ComboBox();
	addAndMakeVisible( comboBox );
	comboBox->addListener( this );
	comboBox->addItemList( MidiInput::getDevices(), 1 );
	if ( adapter.getIndex() != -1 )
		comboBox->setSelectedItemIndex( adapter.getIndex(), dontSendNotification );
}

MidiInputSetupComponent::~MidiInputSetupComponent()
{
}

void MidiInputSetupComponent::paint( Graphics&g )
{
	g.fillAll( Colours::black );
	g.setColour( Colours::grey );
	g.drawRect( getLocalBounds(), 1 );   // draw an outline around the component
}

void MidiInputSetupComponent::resized()
{
	label->setBoundsRelative( 0.0f, 0.0f, 0.25f, 1.0f );
	comboBox->setBoundsRelative( 0.25f, 0.0f, 0.75f, 1.0f );
}

void MidiInputSetupComponent::comboBoxChanged( ComboBox * comboBoxThatHasChanged )
{
	adapter.set( comboBoxThatHasChanged->getSelectedItemIndex() );
}

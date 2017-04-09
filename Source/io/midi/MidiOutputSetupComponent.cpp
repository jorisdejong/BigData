/*
  ==============================================================================

    MidiOutputSetupComponent.cpp
    Created: 9 Apr 2017 12:59:27pm
    Author:  Joris

  ==============================================================================
*/

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "MidiOutputSetupComponent.h"
#include "MidiOutputAdapter.h"

//==============================================================================
MidiOutputSetupComponent::MidiOutputSetupComponent( MidiOutputAdapter& adapter ) : adapter( adapter )
{
	label = new Label( "label", "Out:" );
	addAndMakeVisible( label );
	label->setColour( Label::ColourIds::textColourId, Colours::whitesmoke );

	comboBox = new ComboBox();
	addAndMakeVisible( comboBox );
	comboBox->addListener( this );
	comboBox->addItemList( MidiOutput::getDevices(), 1 );
	if ( adapter.getIndex() != -1 )
		comboBox->setSelectedItemIndex( adapter.getIndex(), dontSendNotification );
}

MidiOutputSetupComponent::~MidiOutputSetupComponent()
{
}

void MidiOutputSetupComponent::paint (Graphics&g)
{
	g.fillAll( Colours::black );
	g.setColour( Colours::grey );
	g.drawRect( getLocalBounds(), 1 );   // draw an outline around the component
}

void MidiOutputSetupComponent::resized()
{
	label->setBoundsRelative( 0.0f, 0.0f, 0.25f, 1.0f );
	comboBox->setBoundsRelative( 0.25f, 0.0f, 0.75f, 1.0f );
}

void MidiOutputSetupComponent::comboBoxChanged( ComboBox * comboBoxThatHasChanged )
{
	adapter.set( comboBoxThatHasChanged->getSelectedItemIndex() );
}

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

void MidiInputSetupComponent::paint( Graphics& )
{

}

void MidiInputSetupComponent::resized()
{
	comboBox->setBoundsRelative( 0.0f, 0.0f, 1.0f, 1.0f );
}

void MidiInputSetupComponent::comboBoxChanged( ComboBox * comboBoxThatHasChanged )
{
	adapter.set( comboBoxThatHasChanged->getSelectedItemIndex() );
}

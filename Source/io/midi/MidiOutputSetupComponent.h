/*
  ==============================================================================

	MidiOutputSetupComponent.h
	Created: 9 Apr 2017 12:59:27pm
	Author:  Joris

  ==============================================================================
*/

#ifndef MIDIOUTPUTSETUPCOMPONENT_H_INCLUDED
#define MIDIOUTPUTSETUPCOMPONENT_H_INCLUDED

#include "../../../JuceLibraryCode/JuceHeader.h"

class MidiOutputAdapter;

//==============================================================================
/*
*/
class MidiOutputSetupComponent :
	public Component,
	public ComboBox::Listener
{
public:
	MidiOutputSetupComponent( MidiOutputAdapter& adapter );
	~MidiOutputSetupComponent();

	void paint( Graphics& ) override;
	void resized() override;

	void comboBoxChanged( ComboBox* comboBoxThatHasChanged ) override;

private:
	ScopedPointer<Label> label;
	ScopedPointer<ComboBox> comboBox;
	MidiOutputAdapter& adapter;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR( MidiOutputSetupComponent )
};


#endif  // MIDIOUTPUTSETUPCOMPONENT_H_INCLUDED

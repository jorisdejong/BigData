/*
  ==============================================================================

    MidiInputSetupComponent.h
    Created: 9 Apr 2017 12:59:14pm
    Author:  Joris

  ==============================================================================
*/

#ifndef MIDIINPUTSETUPCOMPONENT_H_INCLUDED
#define MIDIINPUTSETUPCOMPONENT_H_INCLUDED

#include "../../../JuceLibraryCode/JuceHeader.h"
class MidiInputAdapter;

//==============================================================================
/*
*/
class MidiInputSetupComponent    : 
	public Component,
	public ComboBox::Listener
{
public:
    MidiInputSetupComponent( MidiInputAdapter& adapter);
    ~MidiInputSetupComponent();

    void paint (Graphics&) override;
    void resized() override;

	void comboBoxChanged( ComboBox* comboBoxThatHasChanged ) override;

private:
	ScopedPointer<Label> label;
	ScopedPointer<ComboBox> comboBox;
	MidiInputAdapter& adapter;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiInputSetupComponent)
};


#endif  // MIDIINPUTSETUPCOMPONENT_H_INCLUDED

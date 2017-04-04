/*
  ==============================================================================

    OscOutputSetupComponent.h
    Created: 4 Apr 2017 9:49:55pm
    Author:  Joris

  ==============================================================================
*/

#ifndef OSCOUTPUTSETUPCOMPONENT_H_INCLUDED
#define OSCOUTPUTSETUPCOMPONENT_H_INCLUDED

#include "../../../JuceLibraryCode/JuceHeader.h"

class OscOutputAdapter;

//==============================================================================
/*
*/
class OscOutputSetupComponent    : 
	public Component,
	public TextEditor::Listener
{
public:
    OscOutputSetupComponent( OscOutputAdapter& adapter );
    ~OscOutputSetupComponent();

	void textEditorReturnKeyPressed( TextEditor& ) override;
	void textEditorEscapeKeyPressed( TextEditor& ) override;
	void textEditorFocusLost( TextEditor& ) override;

    void paint (Graphics&) override;
    void resized() override;

private:
	OscOutputAdapter& adapter;

	ScopedPointer<Label> label;
	ScopedPointer<TextEditor> ipEditor;
	ScopedPointer<TextEditor> portEditor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscOutputSetupComponent)
};


#endif  // OSCOUTPUTSETUPCOMPONENT_H_INCLUDED

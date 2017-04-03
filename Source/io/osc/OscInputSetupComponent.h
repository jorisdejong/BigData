/*
  ==============================================================================

	OscInputSetupComponent.h
	Created: 3 Apr 2017 10:51:56pm
	Author:  Joris

  ==============================================================================
*/

#ifndef OSCINPUTSETUPCOMPONENT_H_INCLUDED
#define OSCINPUTSETUPCOMPONENT_H_INCLUDED

#include "../../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class OscInputAdapter;

class OscInputSetupComponent :
	public Component,
	public TextEditor::Listener
{
public:
	OscInputSetupComponent( OscInputAdapter& adapter );
	~OscInputSetupComponent();

	void textEditorReturnKeyPressed( TextEditor& ) override;
	void textEditorEscapeKeyPressed( TextEditor& ) override;
	void textEditorFocusLost( TextEditor& ) override;

	void paint( Graphics& ) override;
	void resized() override;

private:
	OscInputAdapter& adapter;
	void updatePort( int port );

	ScopedPointer<Label> label;
	ScopedPointer<TextEditor> editor;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR( OscInputSetupComponent )
};


#endif  // OSCINPUTSETUPCOMPONENT_H_INCLUDED

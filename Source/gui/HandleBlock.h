/*
  ==============================================================================

    HandleBlock.h
    Created: 23 Mar 2017 12:14:23pm
    Author:  Joris

  ==============================================================================
*/

#ifndef HANDLEBLOCK_H_INCLUDED
#define HANDLEBLOCK_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../io/ControlHandle.h"

//==============================================================================
/*
*/
class HandleBlock    : 
	public Component, 
	public Button::Listener
{
public:
	HandleBlock( ControlHandle* handle, bool isFlipped = false );
    ~HandleBlock();

    void paint (Graphics&) override;
    void resized() override;

	void buttonClicked( Button* b ) override;

	void link();

private:
	bool isFlipped;
	ScopedPointer<TextButton> linkButton;
	ScopedPointer<TextButton> invertButton;

	ControlHandle* handle;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HandleBlock)
};


#endif  // HANDLEBLOCK_H_INCLUDED

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

//==============================================================================
/*
*/
class HandleBlock    : public Component
{
public:
    HandleBlock();
    ~HandleBlock();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HandleBlock)
};


#endif  // HANDLEBLOCK_H_INCLUDED

/*
  ==============================================================================

    SetupComponent.h
    Created: 3 Apr 2017 10:11:22pm
    Author:  Joris

  ==============================================================================
*/

#ifndef SETUPCOMPONENT_H_INCLUDED
#define SETUPCOMPONENT_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SetupComponent    : public Component
{
public:
    SetupComponent();
    ~SetupComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SetupComponent)
};


#endif  // SETUPCOMPONENT_H_INCLUDED

/*
  ==============================================================================

    ParamBlock.h
    Created: 9 Apr 2017 11:55:23am
    Author:  Joris

  ==============================================================================
*/

#ifndef PARAMBLOCK_H_INCLUDED
#define PARAMBLOCK_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../fixture/FixtureParameter.h"
#include "HandleBlock.h"
#include "ParamSlider.h"

//==============================================================================
/*
*/
class ParamBlock    : public Component
{
public:
    ParamBlock( FixtureParameter* param );
    ~ParamBlock();

    void paint (Graphics&) override;
    void resized() override;

	ParamSlider* getSlider();
	OwnedArray<HandleBlock>& getBlocks();

private:
	ScopedPointer<ParamSlider> slider;
	OwnedArray<HandleBlock> blocks;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParamBlock)
};


#endif  // PARAMBLOCK_H_INCLUDED

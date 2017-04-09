/*
  ==============================================================================

    FixtureBlock.h
    Created: 9 Apr 2017 11:55:42am
    Author:  Joris

  ==============================================================================
*/

#ifndef FIXTUREBLOCK_H_INCLUDED
#define FIXTUREBLOCK_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../fixture/Fixture.h"
#include "../fixture/FixtureController.h"
#include "ParamBlock.h"

//==============================================================================
/*
*/
class FixtureBlock    : public Component
{
public:
    FixtureBlock( Fixture* fixture );
    ~FixtureBlock();

    void paint (Graphics&) override;
    void resized() override;

	float getRelativeHeight();

private:
	ScopedPointer<Label> fixtureLabel;
	OwnedArray<ParamBlock> paramBlocks;
	Fixture* fixture;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FixtureBlock)
};


#endif  // FIXTUREBLOCK_H_INCLUDED

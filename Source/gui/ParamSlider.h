/*
  ==============================================================================

    ParamSlider.h
    Created: 23 Mar 2017 8:06:39pm
    Author:  Joris

  ==============================================================================
*/

#ifndef PARAMSLIDER_H_INCLUDED
#define PARAMSLIDER_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class ParamSlider    : public Slider, public Timer
{
public:
    ParamSlider( String name );
    ~ParamSlider();

	void paint (Graphics&) override;
 

	void update( float value );

	void timerCallback() override;

private:
	float outlineOpacity;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParamSlider)
};


#endif  // PARAMSLIDER_H_INCLUDED

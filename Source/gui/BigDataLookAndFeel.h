/*
  ==============================================================================

    BigDataLookAndFeel.h
    Created: 23 Mar 2017 8:10:20pm
    Author:  Joris

  ==============================================================================
*/

#ifndef BIGDATALOOKANDFEEL_H_INCLUDED
#define BIGDATALOOKANDFEEL_H_INCLUDED

#include "JuceHeader.h"

class BigDataLookAndFeel : public LookAndFeel_V1
{
public:


	void drawLinearSlider( Graphics&, int x, int y, int width, int height,
		float sliderPos, float minSliderPos, float maxSliderPos,
		const Slider::SliderStyle, Slider& ) override;

	void drawButtonBackground( Graphics&, Button&, const Colour& backgroundColour,
		bool isMouseOverButton, bool isButtonDown ) override;
};



#endif  // BIGDATALOOKANDFEEL_H_INCLUDED

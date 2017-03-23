/*
  ==============================================================================

	BigDataLookAndFeel.cpp
	Created: 23 Mar 2017 8:10:20pm
	Author:  Joris

  ==============================================================================
*/

#include "BigDataLookAndFeel.h"



void BigDataLookAndFeel::drawLinearSlider( Graphics & g, int x, int y, int width, int height,
	float sliderPos, float, float,
	const Slider::SliderStyle style, Slider &slider )
{
	g.fillAll( slider.findColour( Slider::backgroundColourId ) );

	g.setColour( Colours::whitesmoke.withAlpha( 0.25f ) );
	g.setFont( Font( "Impact", height * 0.66f, Font::italic ) );
	g.drawText( slider.getName(), Rectangle<int>{x, y, width, height}, Justification::centred, false );
	if ( style == Slider::LinearBar )
	{
		g.setColour( slider.findColour( Slider::thumbColourId ) );
		g.fillRect( (int) sliderPos - 1, y, 2, height );
	}
}

void BigDataLookAndFeel::drawButtonBackground( Graphics &g, Button &button, const Colour & backgroundColour, bool isMouseOverButton, bool isButtonDown )
{
	const int width = button.getWidth();
	const int height = button.getHeight();

	const float indent = 2.0f;
	const int cornerSize = jmin( roundToInt( width * 0.4f ),
		roundToInt( height * 0.4f ) );

	Path p;
	p.addRoundedRectangle( indent, indent,
		width - indent * 2.0f,
		height - indent * 2.0f,
		(float) cornerSize );

	Colour bc( backgroundColour.withBrightness( 0.9f ) );

	if ( isMouseOverButton )
	{
		if ( isButtonDown )
			bc = Colours::red;
	}

	g.setColour( bc );
	g.fillPath( p );

	if ( isMouseOverButton )
	{
		g.setColour( Colours::whitesmoke.withAlpha( 0.6f ) );
		g.strokePath( p, PathStrokeType( 1.0f ) );
	}
}


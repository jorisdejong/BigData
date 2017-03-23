/*
  ==============================================================================

    ParamSlider.cpp
    Created: 23 Mar 2017 8:06:39pm
    Author:  Joris

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ParamSlider.h"

//==============================================================================
ParamSlider::ParamSlider( String name ) : Slider( name )
{
	setSliderStyle( juce::Slider::SliderStyle::LinearBar );
	setTextBoxStyle( juce::Slider::NoTextBox, true, 0, 0 );
	setRange( 0.0f, 1.0f );

	outlineOpacity = 0.0f;
}

ParamSlider::~ParamSlider()
{
}

void ParamSlider::paint (Graphics& g)
{
	Slider::paint( g );
	g.setColour( Colours::red.withAlpha( outlineOpacity ) );
	g.drawRect( getLocalBounds(), 2.0f );
}

void ParamSlider::update( float value )
{
	setValue( double( value ), dontSendNotification );
	outlineOpacity = 1.0f;
	startTimerHz( 30 );
}

void ParamSlider::timerCallback()
{
	outlineOpacity -= 0.1f;
	if ( outlineOpacity <= 0.0f )
	{
		outlineOpacity = 0.0f;
		stopTimer();
	}
	repaint();
}

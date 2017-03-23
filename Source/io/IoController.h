/*
  ==============================================================================

	IoController.h
	Created: 22 Mar 2017 7:03:21pm
	Author:  Joris

	IoController ties an input and an output together

  ==============================================================================
*/

#ifndef IOCONTROLLER_H_INCLUDED
#define IOCONTROLLER_H_INCLUDED

#include "JuceHeader.h"

#include "InputAdapter.h"
#include "OutputAdapter.h"

class IoController
{
public:
	IoController( InputAdapter* input, OutputAdapter* output );
	~IoController();

	InputAdapter* getInput();
	OutputAdapter* getOutput();

private:
	ScopedPointer<InputAdapter> input;
	ScopedPointer<OutputAdapter> output;

};



#endif  // IOCONTROLLER_H_INCLUDED

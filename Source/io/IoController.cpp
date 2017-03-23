/*
  ==============================================================================

	IoController.cpp
	Created: 22 Mar 2017 7:03:21pm
	Author:  Joris

  ==============================================================================
*/

#include "IoController.h"

IoController::IoController( String name, InputAdapter* input, OutputAdapter* output ) : name( name ), input( input ), output( output )
{
}

IoController::~IoController()
{
	input = nullptr;
	output = nullptr;
}

InputAdapter* IoController::getInput()
{
	return input;
}

OutputAdapter* IoController::getOutput()
{
	return output;
}

String IoController::getName()
{
	return name;
}

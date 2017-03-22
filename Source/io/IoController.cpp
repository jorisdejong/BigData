/*
  ==============================================================================

    IoController.cpp
    Created: 22 Mar 2017 7:03:21pm
    Author:  Joris

  ==============================================================================
*/

#include "IoController.h"

IoController::IoController()
  {
  }

IoController::~IoController()
{
}

InputAdapter * IoController::getInput()
{
	return input;
}

OutputAdapter * IoController::getOutput()
{
	return output;
}

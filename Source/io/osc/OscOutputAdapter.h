/*
  ==============================================================================

    OscOutputAdapter.h
    Created: 22 Mar 2017 8:30:37pm
    Author:  Joris

  ==============================================================================
*/

#ifndef OSCOUTPUTADAPTER_H_INCLUDED
#define OSCOUTPUTADAPTER_H_INCLUDED

#include "../OutputAdapter.h"

class OscOutputAdapter :
	public OutputAdapter,
	public juce::OSCSender
{
public:
	OscOutputAdapter( String hostname, int port );
	~OscOutputAdapter();

	void sendMessage( OSCMessage m ) override;

private:


};




#endif  // OSCOUTPUTADAPTER_H_INCLUDED

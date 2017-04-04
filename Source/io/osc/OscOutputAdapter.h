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
#include "OscOutputSetupComponent.h"

class OscOutputAdapter :
	public OutputAdapter,
	public juce::OSCSender
{
public:
	OscOutputAdapter();
	~OscOutputAdapter();

	void set( String hostname, int port ) override;
	void sendMessage( OSCMessage m ) override;

	Component* getSetupComponent() override;

	String getIp();
	int getPort();

private:
	int port;
	String ip;

	ScopedPointer<OscOutputSetupComponent> outputSetup;


};




#endif  // OSCOUTPUTADAPTER_H_INCLUDED

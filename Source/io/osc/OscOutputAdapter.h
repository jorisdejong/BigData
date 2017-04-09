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
	OscOutputAdapter();
	~OscOutputAdapter();

	void set( String hostname, int port );
	void sendMessage( OSCMessage m ) override;

	String getIp();
	int getPort();

private:
	int port;
	String ip;
};




#endif  // OSCOUTPUTADAPTER_H_INCLUDED

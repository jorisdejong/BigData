/*
  ==============================================================================

	Hardcoded.cpp
	Created: 23 Mar 2017 11:20:37am
	Author:  Joris

  ==============================================================================
*/

#include "Hardcoded.h"

//#define EYESUPPLY

void Hardcoded::create()
{
	Fixture* globalFixture = new Fixture("Global");
	globalFixture->addParameter(new FixtureParameter("Speed"));
	globalFixture->addParameter(new FixtureParameter("Color"));
	FixtureController::getInstance()->addFixture(globalFixture);


	for (int i = 0; i < 6; i++)
	{
		Fixture* laserFixture = new Fixture("Laser " + String(i + 1));
		laserFixture->addParameter(new FixtureParameter("Brightness"));
		FixtureController::getInstance()->addFixture(laserFixture);
	}
}

void Hardcoded::setupResolume( Fixture* fixture, FixtureParameter* param, int layer, IoController* oscController )
{
	if ( FixtureController::getInstance()->getFixtures().indexOf( fixture ) == 0 )
	{
		switch ( fixture->getParams().indexOf( param ) )
		{
		case 0:
			param->addHandle( new OscControlHandle( "/layer" + String( layer ) + "/video/position/speed", oscController ) );
			break;
		case 1:
			param->addHandle( new OscControlHandle( "/layer" + String( layer ) + "/video/effect1/param2/values", oscController ) );
			break;
		}
	}
	else
	{
		switch ( fixture->getParams().indexOf( param ) )
		{
		case 0:
			int fix = FixtureController::getInstance()->getFixtures().indexOf( fixture ) - 1;
			fix *= 16;
			fix += 8;
			param->addHandle( new OscControlHandle( "/layer" + String( layer ) + "/video/effect2/param" + String( fix ) + "/values", oscController, true ) );
			break;
		}
	}
}

void Hardcoded::assignIos()
{
	File settingsFile = File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory).getChildFile("Octopus/settings.xml");
	ScopedPointer<XmlElement> data = XmlDocument::parse(settingsFile);
	if (data)
	{
		//we're going to have 3 OSC ios
		//first one is KBK, then Kappa, then Eyesupply
		int oscIo = 0;
		forEachXmlChildElement(*data, io)
		{
			if (io->getStringAttribute("type") == "osc")
			{
				OscInputAdapter* input = nullptr;
				OscOutputAdapter* output = nullptr;
				if (XmlElement* inputXml = io->getChildByName("input"))
				{
					input = new OscInputAdapter();
					input->set(inputXml->getIntAttribute("port"));
				}
				if (XmlElement* outputXml = io->getChildByName("output"))
				{
					output = new OscOutputAdapter();
					output->set( outputXml->getStringAttribute( "ip" ), outputXml->getIntAttribute( "port" ) );					
				}
				IoController* oscController = new IoController("Video", input, output);
				FixtureController::getInstance()->addIo(oscController);

				//go through all the params and assign them
				for (Fixture* fixture : FixtureController::getInstance()->getFixtures())
				{
					for (FixtureParameter* param : fixture->getParams())
					{
						switch ( oscIo )
						{
						case 0:
							setupResolume( fixture, param, 27, oscController );
							break;
						case 1:
							if ( FixtureController::getInstance()->getFixtures().indexOf( fixture ) == 0 )
							{
								switch ( fixture->getParams().indexOf( param ) )
								{
								case 0:
									param->addHandle( new OscControlHandle( "/beyond/bla/speed", oscController ) );
									break;
								case 1:
									param->addHandle( new OscControlHandle( "/beyond/bla/color", oscController ) );
									break;
								}
							}
							else
							{
								switch ( fixture->getParams().indexOf( param ) )
								{
								case 0:
									int fix = FixtureController::getInstance()->getFixtures().indexOf( fixture ) - 1;
									param->addHandle( new OscControlHandle( "/beyond/bla/brightness", oscController, true ) );
									break;
								}
							}
							break;
						case 2:
							setupResolume( fixture, param, 13, oscController );
							break;
							
							

						}
					}
				}
				oscIo++;
			}

			else if (io->getStringAttribute("type") == "midi")
			{
				MidiInputAdapter* input = nullptr;
				MidiOutputAdapter* output = nullptr;
				if (XmlElement* inputXml = io->getChildByName("input"))
				{
					input = new MidiInputAdapter();
					input->set(inputXml->getIntAttribute("index"));
				}
				if (XmlElement* outputXml = io->getChildByName("output"))
				{
					output = new MidiOutputAdapter();
					output->set(outputXml->getIntAttribute("index"));
				}
				IoController* midiController = new IoController("Laser", input, output);
				FixtureController::getInstance()->addIo(midiController);

				//go through all the params and assign them
				for (Fixture* fixture : FixtureController::getInstance()->getFixtures())
				{
					for (FixtureParameter* param : fixture->getParams())
					{
						//global fixture
						if (FixtureController::getInstance()->getFixtures().indexOf(fixture) == 0)
						{
							switch (fixture->getParams().indexOf(param))
							{
							case 0:
								param->addHandle(new MidiControlHandle(4, 17, false, midiController));
								break;
							case 1:
								//color translate
								//32 ... 223
								MidiControlHandle* rangedHandle = new MidiControlHandle(4, 8, false, midiController);
								rangedHandle->setRange(16, 111);
								param->addHandle(rangedHandle);
								break;
							}
							
						}
						else
						{
							switch (fixture->getParams().indexOf(param))
							{
							case 0:
								int channel = 1;
								int cc = 17;
								switch (FixtureController::getInstance()->getFixtures().indexOf(fixture))
								{

								case 2:
									cc = 18;
									break;
								case 3:
									cc = 19;
									break;
								case 4:
									channel = 2;
									cc = 16;
									break;
								case 5:
									channel = 2;
									cc = 17;
									break;
								case 6:
									channel = 2;
									cc = 18;
									break;
								}
								param->addHandle(new MidiControlHandle(channel, cc, false, midiController, true));
								break;
							}
						}
					}
				}
			}
		}
		//while we're here, write the midi ios to xml for debugging
		XmlElement* midiDevices = data->getChildByName("MidiDevices");
		if (!midiDevices)
		{
			midiDevices = new XmlElement("MidiDevices");
			data->addChildElement(midiDevices);
		}
		//remove the previous settings and write the new ones
		midiDevices->deleteAllChildElements(); 
		for (String device : MidiInput::getDevices())
		{
			XmlElement* midiInput = new XmlElement("input");
			midiInput->setAttribute("name", device);
			midiDevices->addChildElement(midiInput);
		}
		for (String device : MidiOutput::getDevices())
		{
			XmlElement* midiOutput = new XmlElement("output");
			midiOutput->setAttribute("name", device);
			midiDevices->addChildElement(midiOutput);
		}
		

		data->writeToFile(settingsFile, "");
	}
}

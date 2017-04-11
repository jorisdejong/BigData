/*
  ==============================================================================

	Hardcoded.cpp
	Created: 23 Mar 2017 11:20:37am
	Author:  Joris

  ==============================================================================
*/

#include "Hardcoded.h"

void Hardcoded::create()
{
	Fixture* globalFixture = new Fixture("Global");
	globalFixture->addParameter(new FixtureParameter("Speed"));
	FixtureController::getInstance()->addFixture(globalFixture);

	for (int i = 0; i < 6; i++)
	{
		Fixture* laserFixture = new Fixture("Laser " + String(i + 1));
		laserFixture->addParameter(new FixtureParameter("Brightness"));
		FixtureController::getInstance()->addFixture(laserFixture);
	}
}

void Hardcoded::assignIos()
{
	File settingsFile = File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory).getChildFile("Octopus/settings.xml");
	ScopedPointer<XmlElement> data = XmlDocument::parse(settingsFile);
	if (data)
	{
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
					output->set(outputXml->getStringAttribute("ip"), outputXml->getIntAttribute("port"));
				}
				IoController* oscController = new IoController("Video", input, output);
				FixtureController::getInstance()->addIo(oscController);

				//go through all the params and assign them
				for (Fixture* fixture : FixtureController::getInstance()->getFixtures())
				{
					for (FixtureParameter* param : fixture->getParams())
					{
						if (FixtureController::getInstance()->getFixtures().indexOf(fixture) == 0)
							param->addHandle(new OscControlHandle("/layer9/video/speed/values", oscController));
						else
						{
							switch (fixture->getParams().indexOf(param))
							{
							case 0:
								param->addHandle(new OscControlHandle("/layer9/video/opacity/values", oscController, true));
								break;
							}
						}
					}
				}
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
						if (FixtureController::getInstance()->getFixtures().indexOf(fixture) == 0)
							param->addHandle(new MidiControlHandle(4, 19, false, midiController));
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
		XmlElement* midiDevices = new XmlElement("MidiDevices");
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
		data->addChildElement(midiDevices);

		data->writeToFile(settingsFile, "");
	}
}

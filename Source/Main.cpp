/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"



//==============================================================================
class BigDataApplication  : public JUCEApplication, public Timer
{
public:
    //==============================================================================
    BigDataApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return false; }

    //==============================================================================
    void initialise (const String&) override
    {
        mainWindow = new MainWindow (getApplicationName());

		OscInputAdapter* oscInput = new OscInputAdapter( 10000 );
		OscOutputAdapter* oscOutput = new OscOutputAdapter( "127.0.0.1", 7000 );

		oscController = new IoController( oscInput, oscOutput );

		Fixture* globalFixture = new Fixture( "Global" );
		FixtureParameter* speed = new FixtureParameter( "Speed" );
		ControlHandle* oscHandle = new OscControlHandle( "/layer9/video/speed/values" );
		oscHandle->setIoController( oscController );
		speed->addHandle( oscHandle );
		globalFixture->addParameter( speed );
		FixtureController::getInstance()->addFixture( globalFixture );

		//start running the timer that will process the incoming commands
		startTimerHz( 60 );
    }

	void timerCallback() override
	{
		FixtureController::getInstance()->process();
	}

    void shutdown() override
    {
        mainWindow = nullptr; // (deletes our window)

		oscController = nullptr;
		FixtureController::destroyInstance();
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const String&) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

    //==============================================================================
    /*
        This class implements the desktop window that contains an instance of
        our MainContentComponent class.
    */
    class MainWindow    : public DocumentWindow
    {
    public:
        MainWindow (String name)  : DocumentWindow (name,
                                                    Colours::lightgrey,
                                                    DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new MainContentComponent(), true);

            centreWithSize (getWidth(), getHeight());
            setVisible (true);
        }

        void closeButtonPressed() override
        {
            // This is called when the user tries to close this window. Here, we'll just
            // ask the app to quit when this happens, but you can change this to do
            // whatever you need.
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

        /* Note: Be careful if you override any DocumentWindow methods - the base
           class uses a lot of them, so by overriding you might break its functionality.
           It's best to do all your work in your content component instead, but if
           you really have to override any DocumentWindow methods, make sure your
           subclass also calls the superclass's method.
        */

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    ScopedPointer<MainWindow> mainWindow;
	ScopedPointer<IoController> oscController;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (BigDataApplication)

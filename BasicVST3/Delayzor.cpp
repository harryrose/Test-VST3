//Keep this in, I was debugging linker errors for ages until I spotted this...
#define INIT_CLASS_IID

#include "Delayzor.h"
#include "assert.h"

#include "DelayzorController.h"
#include "VST/pluginterfaces/base/ibstream.h"

using namespace Steinberg::Vst;

Delayzor::Delayzor(void)
{
	setControllerClass(FUID(CONTROLLER_GUID));
}

Delayzor::~Delayzor(void)
{
}


tresult PLUGIN_API Delayzor::initialize(FUnknown * context)
{
	tresult result = AudioEffect::initialize(context);	
	if (result != kResultOk)
	{
		return result;
	}

	//add audio+event input/outputs
	Delayzor::addAudioInput(USTRING("Input 1"),SpeakerArr::kStereo);
	Delayzor::addAudioOutput(USTRING("Output 1"),SpeakerArr::kStereo);


}

//called before the destructor
tresult PLUGIN_API Delayzor::terminate()
{
	return AudioEffect::terminate();
}

//turns the effect on/off
tresult PLUGIN_API Delayzor::setActive(TBool state)
{
	return kResultFalse;
}

//Called before the first process call
tresult PLUGIN_API Delayzor::setupProcessing(ProcessSetup& newSetup)
{
	assert(initBuffers(newSetup.sampleRate)==kResultOk);
	//newsetup.processMode tells us whate processing mode we should be in now.
	return AudioEffect::setupProcessing(newSetup);
}

//This is where we process the sound/events
tresult PLUGIN_API Delayzor::process(ProcessData& data)
{
	//From the Steinberg API

	// finally the process function
	// In this example there are 4 steps:
	// 1) Read inputs parameters coming from host (in order to adapt our model values)
	// 2) Read inputs events coming from host (we apply a gain reduction depending of the velocity of pressed key)
	// 3) Process the gain of the input buffer to the output buffer
	// 4) Write the new VUmeter value to the output Parameters queue

	return kResultFalse;
}

/** for persistence (apparently).  Will have to read more about this, presumably
this gets or sets the state of the instrument so it can be resumed later? **/
tresult PLUGIN_API Delayzor::setState(IBStream * state)
{
	return kResultFalse;
}

tresult PLUGIN_API Delayzor::getState(IBStream * state)
{
	return kResultFalse;
}

//Sorts out inputs and outputs etc.
tresult PLUGIN_API Delayzor::setBusArrangements(SpeakerArrangement * inputs, int32 numIns, SpeakerArrangement * outputs, int32 numOuts)
{
	return kResultFalse;
}

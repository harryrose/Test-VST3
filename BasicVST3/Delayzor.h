/*
 * A Basic Shell of a VST.  This is based v heavily on the "again" example provided
 * in the Steinberg VST 3 API.
 */

#ifndef _Delayzor_H_
#define _Delayzor_H_
#include <stdlib.h>
#include "VST/public.sdk/source/vst/vstaudioeffect.h"

//Define the GUID of the VST Plugin.  Change this to something unique.

#define PLUGIN_GUID1 0xA8E29FFF
#define PLUGIN_GUID2 0x77E24203
#define PLUGIN_GUID3 0x97D7D1B5
#define PLUGIN_GUID4 0xD77767F4

#define PLUGIN_GUID PLUGIN_GUID1,PLUGIN_GUID2,PLUGIN_GUID3,PLUGIN_GUID4


using namespace Steinberg::Vst;

class Delayzor : public AudioEffect
{
private:
	static const unsigned int numberOfInputChannels = 2;
	
	float * buffer[numberOfInputChannels];

	static int nextPowerO2(int x)
	{
		/** Code stolen from 
			http://www.gamedev.net/community/forums/topic.asp?topic_id=313734
			Thanks, Ra
		**/
		x--;
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;
		x++;
		return x;
	}

	tresult initBuffers(const unsigned int size)
	{
		int bufferSize = nextPowerO2(size);
		for(int i = 0; i < numberOfInputChannels; i++)
		{
			if(buffer[i] != NULL)
			{
				free(buffer[i]);
			}
			buffer[i] = (float *) malloc(bufferSize * sizeof(float));
			if(!buffer[i])
			{
				for(;i>=0; i--)
				{
					free(buffer[i]);
					return kResultFalse;
				}
			}
		}
		return kResultOk;
	}

public:
	Delayzor(void);

	static FUnknown * createInstance(void * context)
	{
		return (IAudioProcessor*) new Delayzor();
	}

	//called after the constructor
	tresult PLUGIN_API initialize(FUnknown * context);

	//called before the destructor
	tresult PLUGIN_API terminate();

	//turns the effect on/off
	tresult PLUGIN_API setActive(TBool state);

	//Called before the first process call
	tresult PLUGIN_API setupProcessing(ProcessSetup& newSetup);

	//This is where we process the sound/events
	tresult PLUGIN_API process(ProcessData& data);

	/** for persistence (apparently).  Will have to read more about this, presumably
	this gets or sets the state of the instrument so it can be resumed later? **/
	tresult PLUGIN_API setState(IBStream * state);
	tresult PLUGIN_API getState(IBStream * state);
	
	//Sorts out inputs and outputs etc.
	tresult PLUGIN_API setBusArrangements(SpeakerArrangement * inputs, int32 numIns, SpeakerArrangement * outputs, int32 numOuts);
	~Delayzor(void);
};


#endif //#ifndef _Delayzor_H_
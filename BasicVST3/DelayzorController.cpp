#include "DelayzorController.h"

DelayzorController::DelayzorController(void)
{
}

DelayzorController::~DelayzorController(void)
{
}


tresult PLUGIN_API DelayzorController::initialize(FUnknown * context)
{
	tresult result = EditController::initialize(context);
	if (result != kResultOk)
	{
		return result;
	}

	//define units, parameters etc in here

	return result;
}

tresult PLUGIN_API DelayzorController::terminate()
{
	return EditController::terminate();
}


tresult PLUGIN_API DelayzorController::setComponentState(IBStream * state)
{
	return kResultFalse;
}

/*IPlugView * PLUGIN_API DelayzorController::createView(const char * name)
{
}*/

tresult PLUGIN_API DelayzorController::setState(IBStream * state)
{
	return kResultFalse;
}

tresult PLUGIN_API DelayzorController::getState(IBStream * state)
{
	return kResultFalse;
}

tresult PLUGIN_API DelayzorController::setParamNormalized(ParamID tag, ParamValue value)
{
	return kResultFalse;
}

tresult PLUGIN_API DelayzorController::getParamStringByValue(ParamID tag, ParamValue valueNormalized, String128 string)
{
	return kResultFalse;
}

tresult PLUGIN_API DelayzorController::getParamValueByString(ParamID tag, TChar * string, ParamValue& valueNormalized)
{
	return kResultFalse;
}

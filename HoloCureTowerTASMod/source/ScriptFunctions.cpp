#include <Aurie/shared.hpp>
#include <YYToolkit/shared.hpp>
#include "ScriptFunctions.h"
#include "CommonFunctions.h"
#include "CodeEvents.h"

extern YYTKInterface* g_ModuleInterface;
extern CallbackManagerInterface* callbackManagerInterfacePtr;
extern PFUNC_YYGMLScript origConfirmedHoloHouseManagerCreateScript;
extern std::unordered_map<int, TASCommand> tasCommandMap;
extern int curTASFrame;
extern bool isRunningTAS;

RValue& ConfirmedHoloHouseManagerCreateBefore(CInstance* Self, CInstance* Other, RValue& ReturnValue, int numArgs, RValue** Args)
{
	RValue canControl = g_ModuleInterface->CallBuiltin("variable_instance_get", { Self, "canControl" });
	RValue paused = g_ModuleInterface->CallBuiltin("variable_instance_get", { Self, "paused" });
	RValue quitConfirm = g_ModuleInterface->CallBuiltin("variable_instance_get", { Self, "quitConfirm" });
	RValue towerMode = g_ModuleInterface->CallBuiltin("variable_instance_get", { Self, "towerMode" });
	RValue towerWin = g_ModuleInterface->CallBuiltin("variable_instance_get", { Self, "towerWin" });
	RValue pauseOption = g_ModuleInterface->CallBuiltin("variable_instance_get", { Self, "pauseOption" });
	if (static_cast<int>(lround(pauseOption.AsReal())) == 3)
	{
		callbackManagerInterfacePtr->CancelOriginalFunction();
	}
	return ReturnValue;
}

bool isRightPressed = false;
bool isLeftPressed = false;

RValue& InputCheckBefore(CInstance* Self, CInstance* Other, RValue& ReturnValue, int numArgs, RValue** Args)
{
	if (!isRunningTAS)
	{
		return ReturnValue;
	}

	if (Args[0]->AsString().compare("right") == 0)
	{
		if (tasCommandMap.find(curTASFrame) != tasCommandMap.end())
		{
			if (tasCommandMap[curTASFrame].TASCommandTypePressRight)
			{
				isRightPressed = true;
			}
			else if (tasCommandMap[curTASFrame].TASCommandTypeReleaseRight)
			{
				isRightPressed = false;
			}
		}
		ReturnValue = isRightPressed;
		callbackManagerInterfacePtr->CancelOriginalFunction();
	}
	else if (Args[0]->AsString().compare("left") == 0)
	{
		if (tasCommandMap.find(curTASFrame) != tasCommandMap.end())
		{
			if (tasCommandMap[curTASFrame].TASCommandTypePressLeft)
			{
				isLeftPressed = true;
			}
			else if (tasCommandMap[curTASFrame].TASCommandTypeReleaseLeft)
			{
				isLeftPressed = false;
			}
		}
		ReturnValue = isLeftPressed;
		callbackManagerInterfacePtr->CancelOriginalFunction();
	}
	return ReturnValue;
}

RValue& InputCheckPressedBefore(CInstance* Self, CInstance* Other, RValue& ReturnValue, int numArgs, RValue** Args)
{
	if (tasCommandMap.find(curTASFrame) == tasCommandMap.end())
	{
		return ReturnValue;
	}
	bool hasTASCommand = false;
	if (Args[0]->AsString().compare("actionOne") == 0)
	{
		ReturnValue = tasCommandMap[curTASFrame].TASCommandTypePressCharge;
		hasTASCommand = true;
	}
	else if (Args[0]->AsString().compare("left") == 0)
	{
		ReturnValue = tasCommandMap[curTASFrame].TASCommandTypePressLeft;
		hasTASCommand = true;
	}
	else if (Args[0]->AsString().compare("right") == 0)
	{
		ReturnValue = tasCommandMap[curTASFrame].TASCommandTypePressRight;
		hasTASCommand = true;
	}
	if (hasTASCommand)
	{
		callbackManagerInterfacePtr->CancelOriginalFunction();
	}
	return ReturnValue;
}

RValue& InputCheckReleasedBefore(CInstance* Self, CInstance* Other, RValue& ReturnValue, int numArgs, RValue** Args)
{
	if (tasCommandMap.find(curTASFrame) == tasCommandMap.end())
	{
		return ReturnValue;
	}
	bool hasTASCommand = false;
	if (Args[0]->AsString().compare("actionOne") == 0)
	{
		ReturnValue = tasCommandMap[curTASFrame].TASCommandTypeReleaseCharge;
		hasTASCommand = true;
	}
	else if (Args[0]->AsString().compare("left") == 0)
	{
		ReturnValue = tasCommandMap[curTASFrame].TASCommandTypeReleaseLeft;
		hasTASCommand = true;
	}
	else if (Args[0]->AsString().compare("right") == 0)
	{
		ReturnValue = tasCommandMap[curTASFrame].TASCommandTypeReleaseRight;
		hasTASCommand = true;
	}
	if (hasTASCommand)
	{
		callbackManagerInterfacePtr->CancelOriginalFunction();
	}
	return ReturnValue;
}

RValue& DoAchievementBefore(CInstance* Self, CInstance* Other, RValue& ReturnValue, int numArgs, RValue** Args)
{
	callbackManagerInterfacePtr->CancelOriginalFunction();
	return ReturnValue;
}
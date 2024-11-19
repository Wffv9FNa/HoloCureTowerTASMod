#pragma once
#include "ModuleMain.h"
#include <Aurie/shared.hpp>
#include <YYToolkit/shared.hpp>

struct TASCommand
{
	bool TASCommandTypePressCharge;
	bool TASCommandTypeReleaseCharge;
	bool TASCommandTypePressLeft;
	bool TASCommandTypeReleaseLeft;
	bool TASCommandTypePressRight;
	bool TASCommandTypeReleaseRight;

	TASCommand() : TASCommandTypePressCharge(false), TASCommandTypeReleaseCharge(false), TASCommandTypePressLeft(false), TASCommandTypeReleaseLeft(false), TASCommandTypePressRight(false), TASCommandTypeReleaseRight(false)
	{
	}
};

void PlayerPlatformerCreateAfter(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args);
void InputManagerStepBefore(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args);
void InputManagerStepAfter(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args);
void HoloHouseManagerStepAfter(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args);
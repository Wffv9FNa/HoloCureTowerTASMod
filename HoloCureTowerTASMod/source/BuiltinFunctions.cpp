#include "BuiltinFunctions.h"
#include "ModuleMain.h"

void DrawTextBefore(RValue* Result, CInstance* Self, CInstance* Other, int numArgs, RValue* Args)
{
	if (numArgs >= 3)
	{
		if (Args[2].AsString().compare("TIME") == 0)
		{
			Args[2] = "TAS " + std::string(Args[2].AsString());
		}
	}
}
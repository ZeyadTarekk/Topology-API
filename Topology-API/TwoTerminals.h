#pragma once
#include "Component.h"
class TwoTerminals: public Component
{
	TwoTerminals(string id, string type, map<string, string>netlist, double defaultV, double minV, double maxV);
	string getT1();
	string getT2();
};


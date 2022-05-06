#pragma once
#include "Component.h"
class TwoTerminals :
    public Component
{
public:
	TwoTerminals(string id, string type, vector<pair<string, string>>netlist, double defaultV, double minV, double maxV);
	pair<string, string> getT1();
	pair<string, string> getT2();
};


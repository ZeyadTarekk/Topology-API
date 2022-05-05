#pragma once
#include "Component.h"
class ThreeTerminals :
	public Component
{

public:
	ThreeTerminals(string id, string type, vector<pair<string, string>>netlist, double defaultV, double minV, double maxV);
	pair<string, string> getSource();
	pair<string, string> getDrain();
	pair<string, string> getGate();
};


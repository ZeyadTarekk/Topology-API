#pragma once
#include "Component.h"
class ThreeTerminals :
	public Component
{

public:
	ThreeTerminals(string id, string type, map<string, string>netlist, double defaultV, double minV, double maxV);
	string getSource();
	string getDrain();
	string getGate();
};


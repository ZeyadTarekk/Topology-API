#include "ThreeTerminals.h"

ThreeTerminals::ThreeTerminals(string id, string type, vector<pair<string, string>> netlist, double defaultV, double minV, double maxV):Component(id,type,netlist,defaultV,minV,maxV)
{
}

pair<string, string> ThreeTerminals::getSource()
{
	return netlist[0];
}

pair<string, string> ThreeTerminals::getDrain()
{
	return netlist[1];
}

pair<string, string> ThreeTerminals::getGate()
{
	return netlist[2];
}

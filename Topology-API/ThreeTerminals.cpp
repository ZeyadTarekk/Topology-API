#include "ThreeTerminals.h"

ThreeTerminals::ThreeTerminals(string id, string type, map<string, string> netlist, double defaultV, double minV, double maxV):Component(id,type,netlist,defaultV,minV,maxV)
{
}

string ThreeTerminals::getSource()
{
	return netlist["source"];
}

string ThreeTerminals::getDrain()
{
	return netlist["drain"];
}

string ThreeTerminals::getGate()
{
	return netlist["gate"];
}

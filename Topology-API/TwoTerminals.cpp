#include "TwoTerminals.h"
TwoTerminals::TwoTerminals(string id, string type, vector<pair<string, string>> netlist, double defaultV, double minV, double maxV) :Component(id, type, netlist, defaultV, minV, maxV)
{
}

pair<string,string> TwoTerminals::getT1()
{
	return netlist[0];
}

pair<string, string> TwoTerminals::getT2()
{
	return netlist[1];
}

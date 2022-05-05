#include "TwoTerminals.h"
TwoTerminals::TwoTerminals(string id, string type, map<string, string> netlist, double defaultV, double minV, double maxV) :Component(id, type, netlist, defaultV, minV, maxV)
{
}

string TwoTerminals::getT1()
{
	return netlist["t1"];
}

string TwoTerminals::getT2()
{
	return netlist["t2"];
}

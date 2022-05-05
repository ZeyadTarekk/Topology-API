#include "Component.h"

Component::Component(string id, string type, map<string, string>netlist, double defaultV, double minV, double maxV)
{
	this->id = id;
	this->type = type;
	this->netlist = netlist;
	this->defaultValue = defaultV;
	this->maxValue = maxV;
	this->minValue = minV;
}


string Component::getID()
{
	return this->id;
}

string Component::getType()
{
	return this->type;
}

double Component::getDefaultValue()
{
	return this->defaultValue;
}

double Component::getMinValue()
{
	return this->minValue;
}

double Component::getMaxValue()
{
	return this->maxValue;
}

map<string, string> Component::getNetlist()
{
	return this->netlist;
}

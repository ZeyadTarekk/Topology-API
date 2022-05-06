#pragma once
#include "ThreeTerminals.h"
#include "TwoTerminals.h"
class Topology
{
private:
	string id;
	vector<Component*> components;
	bool isConnected(string netlistNode);
public:
	Topology(string id);
	Topology(string id, vector<Component*> comp);
	void setComponents(vector<Component*> comp);
	string getId();
	void setId(string id);
	vector<Component*> getComponents();
	vector<Component*> getConnectedComponents(string netlistNode);

};


#pragma once
#include<fstream>
#include"Topology.h"
#include "TwoTerminals.h"
#include<nlohmann\json.hpp>
using json = nlohmann::json;

class jsonDealing
{
private:
	Topology* createTopology(json jsonObj);
	void writeComponent(ofstream& out, Component* comp);
public:
	Topology* readJsonFile(string fileName);
	void writeToJsonFile(Topology& top, string fileName);
};


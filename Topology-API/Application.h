#pragma once
#include "JsonDealing.h"
class Application
{
private:
	JsonDealing jsonObj;
	vector<Topology*> topologies;
	int getSelectionFunction();
	Topology* readFunction();
	Topology* getTopologyByID(string id);
	void topologiesIDSFunction();
	void queryDevicesFunction();
	void queryNodeFunction();
	void queryTopologiesFunction();
	void writeFunction();
	void deleteFunction();
	void exitFunction();
	void Run();

public:
	Application();
	~Application();
};


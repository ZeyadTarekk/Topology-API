#include "Topology.h"

bool Topology::isConnected(string netlistNode)
{
	vector<pair<string, string>>vec;
	for (int i = 0; i < components.size(); i++) {
		vec = components[i]->getNetlist();
		for (int j = 0; j < vec.size(); j++) {
			if (vec[j].second == netlistNode)
				return true;
		}
	}
	return false;
}

Topology::Topology(string id)
{
	this->id = id;
}

Topology::Topology(string id, vector<Component*> comp)
{
	this->id = id;
	this->components = comp;
}

void Topology::setComponents(vector<Component*> comp)
{
	this->components = comp;
}

string Topology::getId()
{
	return this->id;
}

vector<Component*> Topology::getComponents()
{
	return this->components;
}

vector<Component*> Topology::getConnectedComponents(string netlistNode)
{
	vector<Component*> componentsVector;
	vector<pair<string, string>>netlistVector;
	if (isConnected(netlistNode)) {
		for (int i = 0; i < components.size(); i++) {
			netlistVector = components[i]->getNetlist();
			for (int j = 0; j < netlistVector.size(); j++) {
				if (netlistVector[j].second == netlistNode)
					componentsVector.push_back(components[i]);
			}
		}
		return componentsVector;
	}
	else {
		return componentsVector;
	}

}

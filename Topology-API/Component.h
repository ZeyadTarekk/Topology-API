#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;
#pragma once
class Component
{
protected:
	string id;
	string type;
	double defaultValue;
	double minValue;
	double maxValue;
	vector<pair<string, string>> netlist;

public:
	Component(string id,string type, vector<pair<string, string>>netlist,double defaultV,double minV,double maxV);
	virtual string getID();
	virtual string getType();
	virtual double getDefaultValue();
	virtual double getMinValue();
	virtual double getMaxValue();
	virtual vector<pair<string, string>> getNetlist();
	
};


#include<iostream>
#include<string>
#include<map>
using namespace std;
#pragma once
class Component
{
private:
	string id;
	string type;
	double defaultValue;
	double minValue;
	double maxValue;
	map<string, string> netlist;

public:
	Component(string id,string type,map<string,string>netlist,double defaultV,double minV,double maxV);
	virtual string getID();
	virtual string getType();
	virtual double getDefaultValue();
	virtual double getMinValue();
	virtual double getMaxValue();
	virtual map<string, string> getNetlist();
	
};


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
	void print();
	string getID();
	string getType();
	double getDefaultValue();
	double getMinValue();
	double getMaxValue();
	map<string, string> getNetlist();
	
};


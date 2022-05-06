#include "APITesting.h"

APITesting::APITesting()
{
}

void APITesting::Testing1()
{
	Topology* top= jsonObj.readJsonFile("notFound.json");
	if (top == nullptr)
		cout << "PASSED Test 1\n";
	else
		cout << "Test 1 Doesn't pass\n";
}

void APITesting::Testing2()
{
	Topology* top = jsonObj.readJsonFile("topology.json");
	if (top == nullptr)
		cout << "Test 2 Doesn't pass\n";
	else
		cout << "PASSED Test 2\n";
}

void APITesting::Testing3()
{
	Topology top("top2");
	int n = top.getComponents().size();
	if(n==0)
		cout << "PASSED Test 3\n";
	else
		cout << "Test 3 Doesn't pass\n";
}

void APITesting::Testing4()
{
	Topology top("top5");
	string s = top.getId();
	if(s=="top5")
		cout << "PASSED Test 4\n";
	else
		cout << "Test 4 Doesn't pass\n";
	
}

void APITesting::Testing5()
{
	Topology top("top15");
	string s = top.getId();
	if (s == "top3")
		cout << "PASSED Test 5\n";
	else
		cout << "Test 5 Doesn't pass\n";
}

void APITesting::Testing6()
{
	vector<pair<string, string>> vec;
	Component comp("x1", "nmos", vec, 0, 0, 0);
	string s = comp.getID();
	if (s == "x1")
		cout << "PASSED Test 6\n";
	else
		cout << "Test 6 Doesn't pass\n";
}

void APITesting::runTests()
{
	Testing1();
	Testing2();
	Testing3();
	Testing4();
	Testing5();
	Testing6();
}

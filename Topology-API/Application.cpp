#include "Application.h"

int Application::getSelectionFunction()
{
	cout << "========================================================\n";
	cout << "To Read a topology from a given JSON file and store it in the memory Enter 1\n";
	cout << "To Write a given topology from the memory to a JSON file Enter 2\n";
	cout << "To Query about which topologies are currently in the memory Enter 3\n";
	cout << "To Delete a given topology from memory Enter 4\n";
	cout << "To Query about which devices are in a given topology Enter 5\n";
	cout << "To Query about which devices are connected to a given netlist node in a given topology Enter 6\n";
	cout << "To Exit Enter 7\n";
	cout << "========================================================\n";
	int x;
	cin >> x;
	return x;

}

Topology* Application::readFunction()
{
	string s;
	cout << "Enter the name of JSON file with the extension i.e: top.json ";
	cin >> s;
	return jsonObj.readJsonFile(s);
}

Topology* Application::getTopologyByID(string id)
{
	for (int i = 0; i < topologies.size(); i++) {
		if (topologies[i]->getId() == id)
			return topologies[i];
	}
	return nullptr;
}

void Application::topologiesIDSFunction()
{
	for (int i = 0; i < topologies.size(); i++)
		cout << topologies[i]->getId() << " ";
}

void Application::queryDevicesFunction()
{
	Topology* top;
	string topID;
	vector<Component*> componentList;
	if (topologies.size() == 0)
		cout << "No topologies found in the memory\n";
	else {
		cout << "Enter the ID of the needed topology to know devices\n";
		cout << "The available topologies in the memory have ids: ";
		topologiesIDSFunction();
		cout << ": ";
		cin >> topID;
		top = getTopologyByID(topID);
		if (top == nullptr)
			cout << "No topologies found with id = " << topID << endl;
		else {
			componentList = top->getComponents();
			cout << "This topology has: " << componentList.size() << " devices\n";
			for (int i = 0; i < componentList.size(); i++) {
				cout << "Device No: " << i + 1 << " with ID: " << componentList[i]->getID() << " and of type: " << componentList[i]->getType() << endl;
			}
		}
	}
}

void Application::queryNodeFunction()
{
	string topID, node;
	Topology* top;
	vector<Component*> connectedComponents;
	if (topologies.size() == 0)
		cout << "No topologies found in the memory\n";
	else {
		cout << "Enter the ID of the needed topology to search for a node\n";
		cout << "The available topologies in the memory have ids: ";
		topologiesIDSFunction();
		cout << ": ";
		cin >> topID;
		cout << "Enter node name: ";
		cin >> node;
		top = getTopologyByID(topID);
		if (top == nullptr)
			cout << "No topologies found with id = " << topID << endl;
		else {
			connectedComponents = top->getConnectedComponents(node);
			if (connectedComponents.size() == 0)
				cout << "No components found connected to node " << node << " in the topology with id: " << topID << endl;
			else {
				cout << "This node connected to " << connectedComponents.size() << " devices\n";
				for (int i = 0; i < connectedComponents.size(); i++) {
					cout << "Device No: " << i + 1 << " with ID: " << connectedComponents[i]->getID() << " and of type: " << connectedComponents[i]->getType() << endl;
				}
			}
		}
	}

}

void Application::queryTopologiesFunction()
{
	cout << "The memory now has " << topologies.size() << " topologies\n";
	if (topologies.size() != 0) {
		cout << "The available topologies in the memory have ids: ";
		topologiesIDSFunction();
		cout << endl;
	}
}

void Application::writeFunction()
{
	string topID, fileName;
	Topology* top;
	if (topologies.size() == 0)
		cout << "No topologies found in the memory\n";
	else {
		cout << "Enter the ID of the needed topology to write\n";
		cout << "The available topologies in the memory have ids: ";
		topologiesIDSFunction();
		cout << ": ";
		cin >> topID;
		cout << "Enter the name of the json file to write without extension i.e: file: ";
		cin >> fileName;
		if (fileName == "") {
			fileName = "default";
			cout << "Invalid file name, file name set to defualt\n";
		}
		top = getTopologyByID(topID);
		if (top == nullptr)
			cout << "No topologies found with id = " << topID << endl;
		else
			jsonObj.writeToJsonFile(*top, fileName);

	}
}

void Application::deleteFunction()
{
	string topID;
	if (topologies.size() == 0)
		cout << "No topologies found in the memory\n";
	else {
		cout << "Enter the ID of the needed topology to delete\n";
		cout << "The available topologies in the memory have ids: ";
		topologiesIDSFunction();
		cout << ": ";
		cin >> topID;
		bool flag = false;
		for (int i = 0; i < topologies.size(); i++) {
			if (topologies[i]->getId() == topID) {
				flag = true;
				delete topologies[i];
				topologies.erase(topologies.begin() + i);
			}
		}
		if (flag)
			cout << "Successfully deleted topology with ID = " << topID << endl;
		else
			cout << "Can't find topology with ID = " << topID << endl;
	}

}

void Application::exitFunction()
{
	cout << "Good bye\n";
	exit(0);
}

void Application::Run()
{
	int code;
	while (true) {
		code = getSelectionFunction();
		switch (code)
		{
		case 1:
			topologies.push_back(readFunction());
			break;
		case 2:
			writeFunction();
			break;
		case 3:
			queryTopologiesFunction();
			break;
		case 4:
			deleteFunction();
			break;
		case 5:
			queryDevicesFunction();
			break;
		case 6:
			queryNodeFunction();
			break;
		case 7:
			exitFunction();
			break;
		default:
			exitFunction();
			break;
		}

	}
}




Application::Application()
{
	Run();
}

Application::~Application()
{
	for (int i = 0; i < topologies.size(); i++)
		delete topologies[i];
}

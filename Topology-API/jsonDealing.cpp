#include "jsonDealing.h"

Topology* JsonDealing::createTopology(json jsonObj)
{
	Topology* newTopology;
	string topologyID = jsonObj["id"];
	vector<Component*> comp;
	for (int i = 0; i < jsonObj["components"].size(); i++) {
		Component* tempComp;
		string id, type;
		double def, minV, maxV;
		vector<pair<string, string>> net;
		id = jsonObj["components"][i]["id"];
		type = jsonObj["components"][i]["type"];
		if (type == "resistor") {
			def = jsonObj["components"][i]["resistance"]["default"];
			minV = jsonObj["components"][i]["resistance"]["min"];
			maxV = jsonObj["components"][i]["resistance"]["max"];
			net.push_back(make_pair("t1", jsonObj["components"][i]["netlist"]["t1"]));
			net.push_back(make_pair("t1", jsonObj["components"][i]["netlist"]["t2"]));
			tempComp = new TwoTerminals(id, type, net, def, minV, maxV);
		}
		else if (type == "nmos") {
			def = jsonObj["components"][i]["m(l)"]["default"];
			minV = jsonObj["components"][i]["m(l)"]["min"];
			maxV = jsonObj["components"][i]["m(l)"]["max"];
			net.push_back(make_pair("drain", jsonObj["components"][i]["netlist"]["drain"]));
			net.push_back(make_pair("gate", jsonObj["components"][i]["netlist"]["gate"]));
			net.push_back(make_pair("source", jsonObj["components"][i]["netlist"]["source"]));
			tempComp = new ThreeTerminals(id, type, net, def, minV, maxV);
		}
		comp.push_back(tempComp);
	}
	newTopology = new Topology(topologyID, comp);

	std::cout << "Successfuly read topology with id: " << topologyID << endl;
	return newTopology;
}

void JsonDealing::writeComponent(ofstream& out, Component* comp)
{
	out << "    {\n";
	out << "      \"type\": \"" << comp->getType() << "\",\n";
	out << "      \"id\": \"" << comp->getID() << "\",\n";
	if (comp->getType() == "resistor") {
		out << "      \"resistance\": {\n";
		out << "        \"default\": " << comp->getDefaultValue() << ",\n";
		out << "        \"min\": " << comp->getMinValue() << ",\n";
		out << "        \"max\": " << comp->getMaxValue() << "\n";
		out << "      },\n";
		out << "      \"netlist\": {\n";
		out << "        \"t1\": \"" << comp->getNetlist()[0].second << "\",\n";
		out << "        \"t2\": \"" << comp->getNetlist()[1].second << "\"\n";
		out << "      }\n";
		out << "    }";
	}
	else if (comp->getType() == "nmos") {
		out << "      \"m(l)\": {\n";
		out << "        \"default\": " << comp->getDefaultValue() << ",\n";
		out << "        \"min\": " << comp->getMinValue() << ",\n";
		out << "        \"max\": " << comp->getMaxValue() << "\n";
		out << "      },\n";
		out << "      \"netlist\": {\n";
		out << "        \"drain\": \"" << comp->getNetlist()[0].second << "\", \n";
		out << "        \"gate\": \"" << comp->getNetlist()[1].second << "\",\n";
		out << "        \"source\": \"" << comp->getNetlist()[2].second << "\"\n";
		out << "      }\n";
		out << "    }";

	}
}

Topology* JsonDealing::readJsonFile(string fileName)
{
	ifstream file;
	json jsonObj;
	try {
		if (fileName.find(".json") == string::npos) {
			cout << "Invalid file name\n";
			return nullptr;
		}
		file.open(fileName, fstream::in);
		if (file.is_open() == false) {
			cout << "File not found\n";
			return nullptr;
		}
		jsonObj = json::parse(file);
		return createTopology(jsonObj);
	}
	catch (string errorMessage) {
		std::cout << errorMessage << endl;
		return nullptr;
	}
	return nullptr;
}



void JsonDealing::writeToJsonFile(Topology& top, string fileName)
{
	vector<Component*> vec = top.getComponents();
	ofstream out(fileName + ".json");
	out << "{" << endl;
	out << "  \"id\": \"" << top.getId() << "\",\n";
	out << "  \"components\": [\n";
	for (int i = 0; i < vec.size(); i++) {
		writeComponent(out, vec[i]);
		if (i != vec.size() - 1)
			out << ",\n";
	}
	out << "\n";
	out << "  ]\n";
	out << "}";
	std::cout << "Successfuly wrote topology with name " << fileName << ".json" << endl;

}

#include<iostream>
#include<fstream>
#include<string>
#include<nlohmann\json.hpp>

using json = nlohmann::json;

using namespace std;
int main() {
	
	ifstream file;
	file.open("topology.json", fstream::in);
	json jsonObject = json::parse(file);
	cout << jsonObject;
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <vector>
#include <cstdlib>

using namespace std;

void find(string serial);

int main(){
	string serial;
	cout << "Input serial: " << endl;
	cin >> serial;
	find(serial);
	return 0;
}

void find(string serial){
	string path = ".";
	vector<string> instances;
	try {
		for(const auto& entry : filesystem::directory_iterator(path)){
			if(entry.is_regular_file() && entry.path().extension() == ".csv"){
				ifstream file(entry.path());
				if(!file.is_open()){
					cerr << "Unable to open file, exiting." << endl;
				}
				string line;
				while(getline(file,line)){
					istringstream iss(line);
					string field;
					getline(iss,field,',');
					getline(iss,field,',');
					getline(iss,field,',');
					if(field == serial){
						instances.push_back(entry.path().string());
					}
				}
			}
		}
		if(instances.size() > 0){
			cout << "Serial found in " << instances.size() << " surplus sheets: " << endl;
			for(int i = 0; i < instances.size(); i++){
				cout << instances[i] << endl;
			}
		} else {
			cout << "Serial not found in surplus sheets." << endl;
		}
	} catch (const filesystem::filesystem_error& e){
		cerr << "Error accessing directory: " << e.what() << endl;
	}
}

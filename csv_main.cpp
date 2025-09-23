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
  find(serial);
  return 0;
}

void find(int serial){
	string path = "filepath here";
	vector<string> instances;
	try {
		for(const auto& entry : filesystem::directory_iterator(path)){
			if(filesystem::is_regular_file(entry.status())){
				ifstream file(entry.path().filename());
				if(!file.is_open){
					cerr << "Unable to open file, exiting." << endl;
					return 0;
				}
				string line;
				while(getline(file, line)){
					istringstream iss(line);
					string field;
					getline(iss, field, ',');
					getline(iss, field, ',');
					getline(iss, field, ',');
					if(field == serial){
						instances.push_back(file);
					}
				}
				
			} else {
				cout << "Irregular file, exiting." << endl;
        return 0;
			}
		}
		if(instances.size() > 0){
			cout << "Serial found in " << instances.size() << " other surplus sheets:" << endl;
			for(int i = 0; i < instances.size(); i++){
				cout << instances[i] << endl;
			}
		} else {
			cout << "Serial not found in other surplus sheets." << endl;
		}
	} catch (const filesystem::filesystem_error& e){
		cerr << "Error accessing this directory: " << e.what() << endl;
	}
}




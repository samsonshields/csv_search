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
	cout << "Input Serial Number to Search For: " << endl;
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
				int row = 0;
				while(getline(file,line)){
					row++;
					if(row < 11) continue;
					istringstream ss(line);
					string field;
					int col = 0;
					while(getline(ss,field,',')){
						col++;
						if(col==6){
							if(field == serial){
								instances.push_back(entry.path().string());
							}
							break;
						}
					}
				}
			}
		}
		if(instances.size() > 0){
			cout << endl;
			cout << "Serial Number found in " << instances.size() << " Surplus sheet(s): " << endl;
			for(int i = 0; i < instances.size(); i++){
				cout << instances[i] << endl;
			}
		} else {
			cout << endl;
			cout << "Serial Number not found in Surplus sheets." << endl;
		}
	} catch (const filesystem::filesystem_error& e){
		cout << endl;
		cerr << "Error accessing directory: " << e.what() << endl;
	}
}

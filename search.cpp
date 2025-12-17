#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <vector>
#include <cstdlib>

using namespace std;

void find(string val);

int main(){
	string nameNum;
	cout << "Input name/number to search for: " << endl;
	cin >> nameNum;
	find(nameNum);
	return 0;
}

void find(string val){
	string path = ".";
	// change rowNum to whatever your desired row is
	int rowNum = 1234;
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
					if(row < rowNum) continue;
					istringstream ss(line);
					string field;
					int col = 0;
					while(getline(ss,field,',')){
						col++;
						if(col==6){
							if(field == val){
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
			cout << "Found in " << instances.size() << " sheet(s): " << endl;
			for(int i = 0; i < instances.size(); i++){
				cout << instances[i] << endl;
			}
		} else {
			cout << endl;
			cout << "Not found in sheets." << endl;
		}
	} catch (const filesystem::filesystem_error& e){
		cout << endl;
		cerr << "Error accessing directory: " << e.what() << endl;
	}
}

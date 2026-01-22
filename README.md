This program was created as a tool for IT to check intradepartmental excel sheets to maintain unique entries but can easily be repurposed and is not specific to current implementation

In this repo is an c++ program that searches through excel sheets based on row parameter, finds duplicates, and gives you both the amount of duplicates and which sheets they appear in, if any

Both the scripts pull from current working directory

To convert excel sheets to csv files, run the python script in the same directory as your excel sheets. It will, if one does not already exit, create a folder named "csv_out" with all of your newly converted .csv files

Compile the search executable and move it to csv_out, then run from there

To compile search.cpp, please use "g++ -std=c++17 search.cpp -o whatever_name_you_want"

In this repo is an executable that searches through excel sheets based on row parameter, finds duplicates, and gives you both the amount of duplicates and which sheets they appear in

Both the Python Script and Executable pull from current working directory

To convert excel sheets to csv files, run the python script in the same directory as your excel sheets. It will, if one does not already exit, create a folder named "csv_out" with all of your newly converted .csv files

Move the search executable to csv_out, and run from there

If making changes to search.cpp, to compile again, use g++ -std=c++17 search.cpp -o whatever_name_you_want

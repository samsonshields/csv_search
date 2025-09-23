To convert surplus excel sheets to csv files, run the python script in the same directory as your excel sheets. It will, if not already existing, create a folder named "csv_out" with all of your newly converted .csv files
Move the search executable to csv_out, and run from there
If making changes to search.cpp, to compile use g++ -std=c++17 search.cpp -o search

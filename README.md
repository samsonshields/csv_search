In this repo is an executable which searches through all current and previous surplus sheets and finds duplicate serial numbers, giving you the amount of duplicates and which sheets it appears in

It is compiled from a cpp file I wrote, alongside a python script I had ChatGPT make to convert all surplus sheets to csv for standardization and usability across environments

Both the Python Script and Executable pull from current working directory

To convert surplus excel sheets to csv files, run the python script in the same directory as your excel sheets. It will, if not already existing, create a folder named "csv_out" with all of your newly converted .csv files

Move the search executable to csv_out, and run from there

If making changes to search.cpp, to compile again, use g++ -std=c++17 search.cpp -o whatever_name_you_want

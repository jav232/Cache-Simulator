#include<iostream>
#include<cstdlib>   // for atoi
#include<fstream>
#include "cache_sim.h"
using namespace std;
const int MAX_SIZE = 1000;
string filename;
int main(int argc, char*argv[]) {
    /* check if the correct number of arguments have been passed; bail otherwise */
    if (argc < 4){
        cout << "Usage: " << endl;
        cout << "   ./cache num_entries associativity filename" << endl;
        return 0;
    }
    string input_filename = filename + "_input";
    string output_filename = filename + "_output";

    ofstream output;
    ifstream input;

    /* get args; all args come in as strings; need to convert to int with atoi() */
    unsigned entries = atoi(argv[1]);
    unsigned assoc = atoi(argv[2]);
    input_filename = argv[3];
    input.open(input_filename);
    if (!input.is_open()) {
        cerr << "Could not open input file " << input_filename << ". Exiting ..." << endl;
        exit(0);
    }

    unsigned long *nums = new unsigned long[MAX_SIZE];
    int count = 0;
    while (!input.eof() && count < MAX_SIZE) {
        input >> nums[count];
        count++;
    }

    input.close();

    /* open output file stream for writing */
    output.open(output_filename);
    /* no need to check if output file is open; we will create new file if it doesn't exist;
       overwrite otherwise */
    for (int i = 0; i < count; i++){
        output << "ADDR : " << nums[i] << endl;
    }
    /* close output stream */
    output.close();

    /* print the args */
    cout << "Number of entries: " << entries << endl;
    cout << "Associativity: " << assoc << endl;
    cout << "Input File Name: " << input_filename << endl;

    return 0;
}

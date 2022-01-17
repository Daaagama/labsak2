#include <iostream>
#include <getopt.h>

#define no_argument 0
#define required_argument 1 
#define optional_argument 2

using namespace std;

/* Available flags: */
/*     -c, --compile: compile */
/*     -o, --output: output file name */
/*     -c, --clean: clean temp files after compilation */
/*     -h, --help: help */
/*     -v, --version: version */


void show_help_message() {
    cout << "Usage: lab3 -c input_file [options]" << endl
         << "Options:" << endl
         << "   -c, --compile       input file to compile" << endl
         << "   -o, --output        compiled file name" << endl
         << "   --clean             remove temporary files after compilation" << endl
         << "   -h, --help          display this information and exit" << endl
         << "   -v, --version       display version information and exit" << endl
         << endl
         << "Usage example:" << endl
         << "lab3 -c main.cpp -o main --clean" << endl
         << endl
         << "Exit codes:" << endl
         << "   0   compiled successfully" << endl
         << "   1   compilation failed" << endl
         << "   2   invalid arguments provided" << endl;
}

void compile(string inFile, string outFile, bool clean) {
    cout << "Compiling " << inFile << "... Done!" << endl
         << "Compiled file: " << outFile << endl;
    if (clean) {
        cout << "Cleaning up... Done!" << endl;
    }
}

int main (int argc, char **argv) {
    int hflag = 0;
    int vflag = 0;
    int cflag = 0;
    string inFile = "";
    string outFile = "";
    int index = 0;
    int c;

    opterr = 0;

    const struct option longopts[] =
    {
        {"version", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {"compile", required_argument, 0, 'c'},
        {"output", required_argument, 0, 'o'},
        {"clean", no_argument, 0, 0},
        {0,0,0,0},
    };

    while ((c = getopt_long(argc, argv, "vhc:o:", longopts, &index)) != -1)
        switch (c)
            {
            case 0:
                cflag = 1;
                break;
            case 'v':
                vflag = 1;
                break;
            case 'h':
                hflag = 1;
                break;
            case 'c':
                inFile = optarg;
                break;
            case 'o':
                outFile = optarg;
                break;
            case '?':
                cout << "lab3: unrecognized option: -" << char(optopt) << endl
                     << "Use --help to get list of available arguments" << endl;
                return 2;
            }

    if (hflag) {
        show_help_message();
        return 0;
    } else if (vflag) {
        cout << "lab3 version 0.1" << endl;
        return 0;
    } else if (inFile != "") {
        if (outFile == "") {
            outFile = inFile + ".bin";
        }
        compile(inFile, outFile, cflag);
        return 0;
    } else {
        cout << "lab3: no input files" << endl;
        return 2;
    }
        
}

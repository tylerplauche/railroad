#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stack>
#include <vector>

#include "deque.h"
#include "car.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

using namespace std;
int main(int argc, char *argv[]) {
    // parse input file
    VS_MEM_CHECK
    ifstream in(argv[1]);
    ofstream out(argv[2]);

    string line, command;
    int data;
    Deque<int> myDeque;
    while (getline(in, line))
    {
        istringstream iss(line);
        iss >> command;
        if (line.substr( 0, 4) == "Add:")
        {
            out << line;
            iss >> data;
            if (line.substr(0, 11) == "Add:station")
            {
                myDeque.push_front(data);
                out << " OK";
            }
            out << endl;

        }
        if (line.substr( 0, 7) == "Remove:")
        {
            out << line << endl;
        }
        if (line.substr( 0, 5) == "Train")
        {
            out << line << endl;
        }
        if (line.substr( 0, 5) == "Size:")
        {
            out << line << endl;
        }
    }

    cout << "Hello, World!" << endl;
    return 0;
}

//
//  main.cpp
//  Eight Puzzle
//
//  Created by Jimmy Blundell on 2/3/20.
//  Copyright © 2020 Jimmy Blundell. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>
#include "functions.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
   
    ifstream programDataStream;
    vector<string> puzzleStrings;
    string puzzleInStringFormat = "";
    string temp;
    map<string, pair<int, int>> coordinateMap;
    
    
    generateCoordinateMap(coordinateMap);
    
    
    programDataStream.open("program-1-data.txt");
    if (!programDataStream.is_open())
    {
        cout << "Couldn't open file." << endl;
        return -1;
    }
    
    while (!programDataStream.eof())
    {
        for (int i = 0; i < 9; i++)
        {
            programDataStream >> temp;
            puzzleInStringFormat += temp;
            temp = "";
        }
        puzzleStrings.push_back(puzzleInStringFormat);
        puzzleInStringFormat = "";
    }
    
}

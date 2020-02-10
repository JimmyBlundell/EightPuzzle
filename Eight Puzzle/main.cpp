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
#include <chrono>
#include <map>
#include <unordered_set>
#include <queue>
#include <cstdlib>
#include <sstream>
#include "functions.hpp"

using namespace std;

int main()
{
    
    ifstream programDataStream;
    
    vector<string> puzzleStrings;
    
    string puzzleInStringFormat = "";
    string temp;
    const string goalState = "123456780";
    
    vector<string> solutionVec;
    
    map<string, pair<int, int>> coordinateMap;
    unordered_set<string> visitedSet;
    
    //Used for selecting the move with the lowest cost
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    //Mapping coordinates for quicker calculations of heuristic values
    generateCoordinateMap(coordinateMap);
    
    
    programDataStream.open("program-1-data.txt");
    if (!programDataStream.is_open())
    {
        cout << "Couldn't open file." << endl;
        return -1;
    }
    
    //Convert text file to strings representing puzzles, then push into vector. File must end ath the last digit of last puzzle (no extra spaces) or this will include an empty space on the array
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
    
    //Loop through puzzleStrings vector, solving each puzzle
    
    auto t1 = chrono::high_resolution_clock::now();
    
    ofstream ostream;
    ostream.open("results.txt");
    if (ostream.is_open())
    {

        auto puzzStrItr = puzzleStrings.begin();
        while (puzzStrItr != puzzleStrings.end())
        {
            if (!isSolvable(*puzzStrItr))
            {
                ostream << "Cannot be solved!" << "\n";
                ++puzzStrItr;
            }
            string first = *puzzStrItr;
        
            Node tempNode(first);
        
            tempNode.costSoFar = 0;
            tempNode.heuristicCost = heuristicValue(tempNode.puzzleMatrix, coordinateMap);
            tempNode.totalCost = tempNode.costSoFar + tempNode.heuristicCost;
        
            ++puzzStrItr;
        
            string ans = aStarAlgorithm(tempNode, goalState);
        
            ostream << ans << "\n";
        }
    }
    ostream.close();
    
    auto t2 = chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    cout << duration << "microseconds to solve all puzzles!" << endl;;
    
    return 0;
}
    

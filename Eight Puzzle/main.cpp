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
    
    map<string, pair<int, int>> coordinateMap;
    unordered_set<string> visitedSet;
    
    //Used for selecting the move with the lowest cost
    priority_queue<pair<string, int>> pq;
    
    //Global value to keep track of heuristic value for each puzzle state as we are solving
    int heuristic = INT_MAX;
    
    //Mapping coordinates for quicker calculations of heuristic values
    generateCoordinateMap(coordinateMap);
    
    
    programDataStream.open("program-1-data.txt");
    if (!programDataStream.is_open())
    {
        cout << "Couldn't open file." << endl;
        return -1;
    }
    
    //Convert text file to strings representing puzzles, then push into vector. File must end with last digit of last puzzle (no extra spaces) or this will include an empty space on
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
    
    //TODO: Loop through puzzleStrings vector, solving each puzzle
    
    vector<string> moves;
    auto itr = puzzleStrings.begin();
    
    while (itr != puzzleStrings.end())
    {
        if (!isSolvable(*itr))
        {
            cout << "Cannot solve the puzzle!" << endl;
            ++itr;
            continue;
        }
        
        vector<vector<string>> currentPuzzle = stringToMatrix(*itr);
        
        while (heuristic != 0)
        {
            
            vector<vector<string>> leftMove = currentPuzzle;
            vector<vector<string>> rightMove = currentPuzzle;
            vector<vector<string>> upMove = currentPuzzle;
            vector<vector<string>> downMove = currentPuzzle;
            
            pair<int, int> coordinates = findSlider(currentPuzzle);
            int xcord = coordinates.first;
            int ycord = coordinates.second;
            
            if (moveLeft(leftMove, xcord, ycord))
            {
                int leftMoveHeuristic = heuristicValue(leftMove, coordinateMap);
                
            }
            
            if (moveRight(rightMove, xcord, ycord))
            {
                int rightMoveHeuristic = heuristicValue(rightMove, coordinateMap);
                
            }
            
            if (moveUp(upMove, xcord, ycord))
            {
                int upMoveHeuristic = heuristicValue(upMove, coordinateMap);
                
            }
            
            if (moveDown(downMove, xcord, ycord))
            {
                int downMoveHeuristic = heuristicValue(downMove, coordinateMap);
                
            }
            
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
    
}

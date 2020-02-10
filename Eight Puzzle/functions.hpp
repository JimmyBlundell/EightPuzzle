//
//  functions.hpp
//  Eight Puzzle
//
//  Created by Jimmy Blundell on 2/3/20.
//  Copyright © 2020 Jimmy Blundell. All rights reserved.
//

#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <sstream>
#include <stdio.h>
using namespace std;


#ifndef functions_hpp
#define functions_hpp

#endif /* functions_hpp */

vector<vector<string>> stringToMatrix(string &str);
string matrixToString(vector<vector<string>> &vec);

void generateCoordinateMap(map<string, pair<int, int>> &coordinateMap);

int heuristicValue(vector<vector<string>> &startState, map<string, pair<int, int>> &coordinateMap);

bool alreadyVisited(string, unordered_set<string> &visitedSet);

pair<int, int> findSlider(vector<vector<string>> &puzzleMatrix);

bool moveUp(vector<vector<string>> &puzzleMatrix, int i, int j);
bool moveDown(vector<vector<string>> &puzzleMatrix, int i, int j);
bool moveLeft(vector<vector<string>> &puzzleMatrix, int i, int j);
bool moveRight(vector<vector<string>> &puzzleMatrix, int i, int j);

bool isSolvable(string &puzzleString);

struct Node
{
    string path;
    string puzzleString;
    
    vector<vector<string>> puzzleMatrix;
    
    int costSoFar;
    int heuristicCost;
    int totalCost;
    
    bool operator>(const Node& node) const
    {
        return totalCost > node.totalCost;
    }

    Node(string str)
    {
        this->puzzleString = str;
        
        vector<vector<string>> puzzle;
        int pos = 0;
        
        for (int i = 0; i < 3; i++)
        {
            vector<string> row;
            
            for (int j = 0; j < 3; j++)
            {
                string digit(1, str[pos]);
                row.push_back(digit);
                pos++;
            }
            puzzle.push_back(row);
        }
        this->puzzleMatrix = puzzle;
    }
    
    ~Node() {}
};

string aStarAlgorithm(Node node, string goalState);

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

bool moveUp(vector<vector<string>> &puzzleMatrix, int i, int j);
bool moveDown(vector<vector<string>> &puzzleMatrix, int i, int j);
bool moveLeft(vector<vector<string>> &puzzleMatrix, int i, int j);
bool moveRight(vector<vector<string>> &puzzleMatrix, int i, int j);

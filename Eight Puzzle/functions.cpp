//
//  functions.cpp
//  Eight Puzzle
//
//  Created by Jimmy Blundell on 2/3/20.
//  Copyright © 2020 Jimmy Blundell. All rights reserved.
//

#include "functions.hpp"
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;

//Defining coordinate type because I don't know if I need to do it everywhere ;)
typedef pair<int, int> coordinates;


vector<vector<string>> stringToMatrix(string &str)
{
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
    
    return puzzle;
}

string matrixToString(vector<vector<string>> &vec)
{
    string puzzle;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            puzzle += vec[i][j];
        }
    }
    
    return puzzle;
}

int heuristicValue(vector<vector<string>> &startState, map<string, pair<int, int>> &coordinateMap)
{

    int temp;
    int heuristicVal = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            map<string, pair<int, int>>::iterator itr = coordinateMap.find(startState[i][j]);
            temp = (abs(i - itr->second.first) + abs(j - itr->second.second));
            heuristicVal += temp;
        }
    }
    return heuristicVal;
    
}

bool alreadyVisited(string str, unordered_set<string> visitedSet)
{
    
    unordered_set<string>::iterator itr = visitedSet.find(str);
    
    if (itr == visitedSet.end())
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

void generateCoordinateMap(map<string, pair<int, int>> &coordinateMap)
{
    
    string s1 = "1";
    string s2 = "2";
    string s3 = "3";
    string s4 = "4";
    string s5 = "5";
    string s6 = "6";
    string s7 = "7";
    string s8 = "8";
    string sEmpty = "0";
    
    pair<int, int> c1 (0, 0);
    pair<int, int> c2 (0, 1);
    pair<int, int> c3 (0, 2);
    pair<int, int> c4 (1, 0);
    pair<int, int> c5 (1, 1);
    pair<int, int> c6 (1, 2);
    pair<int, int> c7 (2, 0);
    pair<int, int> c8 (2, 1);
    pair<int, int> cEmpty (2, 2);
    
    coordinateMap.insert(pair<string, pair<int, int>>(s1, c1));
    coordinateMap.insert(pair<string, pair<int, int>>(s2, c2));
    coordinateMap.insert(pair<string, pair<int, int>>(s3, c3));
    coordinateMap.insert(pair<string, pair<int, int>>(s4, c4));
    coordinateMap.insert(pair<string, pair<int, int>>(s5, c5));
    coordinateMap.insert(pair<string, pair<int, int>>(s6, c6));
    coordinateMap.insert(pair<string, pair<int, int>>(s7, c7));
    coordinateMap.insert(pair<string, pair<int, int>>(s8, c8));
    coordinateMap.insert(pair<string, pair<int, int>>(sEmpty, cEmpty));
    
}

pair<int, int> findSlider(vector<vector<string>> &puzzleMatrix)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzleMatrix[i][j] == "0")
            {
                return pair<int, int> (i, j);
            }
        }
    }
    cout << "Something wrong with puzzle - Couldn't find slider!" << endl;
    return pair<int, int> (-1, -1);
}

bool moveUp(vector<vector<string>> &puzzleMatrix, int i, int j)
{
    if (i - 1 < 0)
    {
        return false;
    }
    else
    {
        string temp = puzzleMatrix[i][j];
        puzzleMatrix[i][j] = puzzleMatrix[i-1][j];
        puzzleMatrix[i-1][j] = temp;
        return true;
    }
}

bool moveDown(vector<vector<string>> &puzzleMatrix, int i, int j)
{
    if (i + 1 > 2)
    {
        return false;
    }
    else
    {
        string temp = puzzleMatrix[i][j];
        puzzleMatrix[i][j] = puzzleMatrix[i+1][j];
        puzzleMatrix[i+1][j] = temp;
        return true;
    }
}

bool moveLeft(vector<vector<string>> &puzzleMatrix, int i, int j)
{
    if (j - 1 < 0)
    {
        return false;
    }
    else
    {
        string temp = puzzleMatrix[i][j];
        puzzleMatrix[i][j] = puzzleMatrix[i][j-1];
        puzzleMatrix[i][j-1] = temp;
        return true;
    }
}

bool moveRight(vector<vector<string>> &puzzleMatrix, int i, int j)
{
    if (j + 1 > 2)
    {
        return false;
    }
    else
    {
        string temp = puzzleMatrix[i][j];
        puzzleMatrix[i][j] = puzzleMatrix[i][j+1];
        puzzleMatrix[i][j+1] = temp;
        return true;
    }
}

bool isSolvable(string &puzzleString)
{
    int inversions = 0;
    
    stringstream str1;
    stringstream str2;
    
    for (int i = 0; i < 9-1; i++)
    {
        for (int j = i+1; j < 9; j++)
        {
            char c1 = puzzleString[i];
            char c2 = puzzleString[j];
            
            //Integer value for any digit is the digit minus '0' or 48.
            int x = c1 - '0';
            int y = c2 - '0';
            
            
            if (x == 0 || y == 0)
            {
                continue;
            }
            if (x > y)
            {
                inversions++;
            }
        }
    }
    
    if (inversions % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}




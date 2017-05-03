/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: C-60
 *
 * Created on May 2, 2017, 7:59 PM
 */

//#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#define debuggg





using namespace std;

class Node {
    

};


class Map{
public:
    
    //vector<bool><bool>
    bool ** grid;
    
    Map(){
        
    }
    
    
    void loadMap(){
string tmp = "perfect4k.png";

#ifndef debuggg 


        cout << "Please give file name" << endl;
        cin >> tmp;
        
#endif        
        
        //create file object, read file object, check if null
        FILE* pFile;
        pFile = fopen(tmp.c_str(), "r");
        if(pFile == NULL){
            cout << "Error with file" << endl;
            exit(0);
        } 
        
        //int width;
       // int height;
        
        //cout << "Input "
        
        
        
        
        //read header of file to get size
        char info[54];
        fread(info, sizeof(char), 54, pFile);
        
        //pixel width/height
        char tmpB[4];
        
        memcpy(tmpB, info+16, 4);
        int width = (tmpB[0]<<24) + (tmpB[1]<<16) + (tmpB[2]<<8) + (tmpB[3]<<0);//(int)strtol(tmpB, NULL, 16);
        
        memcpy(tmpB, info+20, 4);
        int height = (tmpB[0]<<24) + (tmpB[1]<<16) + (tmpB[2]<<8) + (tmpB[3]<<0);
        
        
        
        
        
     
        //create an array of width size, each slot holds an array --below
        grid = new bool *[width];
        
        //creates width number of arrays of height size
        for(int i = 0; i < width; ++i){
            grid[i] = new bool[height];
        }
        
        int size = width*height;
        
        int pixelNum = 0;
        //tmp = 0;
        char bValue;
        
        //read data to grid from pFile;
        for(int i = 0; i < size; i+=3){
            fseek(pFile, i , 54);
            fread(&bValue, sizeof(char), 1, pFile);
            
            //grid[pixelNum/width][pixelNum%height] = 
            pixelNum += 1;
        }   
    }
    
    
    
    




};







/*
 * 
 */
int main(int argc, char** argv) {
    
    Map* newMap = new Map();
    
    newMap->loadMap();

    return 0;
}


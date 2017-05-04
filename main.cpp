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
#define cimg_display 0
#include "CImg.h"



#define debuggg


using namespace std;
using namespace cimg_library; 

class Node {
    

};


class Map{
public:
    
    bool ** grid;
    
    Map(){
        
    }
    
    
    void loadMap(){
string tmp = "small.ppm";

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
        
        CImg<int> image("small.ppm");
        
        //get image width and height
        int height = image.height();
        int width = image.width();  
        
        bool grid[width][height];
        
        
        //x,y,depth,color coordinates of pixels
        //R = 0 = black false : R255 = white true
        bool pixvalR = image(0,0,0,0);
        pixvalR = image(1,0,0,0);
        bool pixelC;
        
        
        //seed grid[width][height] with true = white false = black
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                pixelC = image(i,j,0,0);
                grid[j][i] = pixelC;
            }
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


#include "test.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include "../renderArt.hpp"
#include "../readArt.hpp"
#include "../terminalHelpers.hpp"
#include "../textBox.hpp"
#include "../inputListener.hpp"
#include "../startScreen.hpp"
#include "../main.cpp"


std::string listenerType;
const int numWalls = 4;
const std::string room1[numWalls] = {"art/room1/W1.txt", "art/room1/W2.txt", "art/room1/W3.txt", "art/room1/W4.txt"};
const std::string room1ZOOMED[numWalls] = {"art/room1/zoomed/W1Zoom.txt", "", "art/room1/zoomed/W3Zoom.txt", ""};
bool room1VIEWED[numWalls] = {false, false, false, false};
bool room1ZOOMEDVIEWED[numWalls] = {false, false, false, false};


const std::string room2[numWalls] = {"art/f1r1w2.txt", "art/f1r1w3.txt", "art/f1r1w4.txt", "art/skull.txt"};
const std::string room3[numWalls] = {"art/f1r1w2.txt", "art/f1r1w3.txt", "art/f1r1w4.txt", "art/skull.txt"};
const std::string room4[numWalls] = {"art/f1r1w2.txt", "art/f1r1w3.txt", "art/f1r1w4.txt", "art/skull.txt"};

std::string listenerType = "RoomLeftRight";
int roomNumber = 1;
int currentWallIndex = 0;
char** art = nullptr;
int artWidth = 0, artHeight = 0;
int totalConsoleHeight = 0;
int totalConsoleWidth = 0;
int  fullScreenTextBoxHeight = 0;
char input = ' ';
bool running = true;
bool zoomed = false;

// Checks if the images for the rooms being rendered are the correct dimensions
bool imageSize(const std::string& filename, char** &art, int &artWidth, int &artHeight){
    // loop through walls in room 1
    // get their corrosponding array
    // test the size of the array to determine height / width
    // if one fails crash
    art = readFileTo2DArray(filename, artWidth, artHeight);
    if(artWidth == 660 && artHeight == 64){
        return true;
    }else{
        throw std::runtime_error("Incorrect image size in " + filename + ", expcted (660 x 63) -> UTF8");
        return false;
    }
}

// main method to handle al ltests
int main(){

    // tests for image sizes
    for(int i = 0 ; i < 4; i++){
        if(!imageSize(room1[i], art, artWidth, artHeight)){
            return 1;
        }
    }
    std::cout << "ALL ROOM ART IS CORRECT <<<< TEST PASSED >>>>>" << std::endl;
    return 0;
}

// int testMain(){
    
//     // tests for image sizes
//     bool result = imageSize();
//     return result;
//     running = false;
// }


#include "pauseMenu.hpp"

void pauseMenu(bool currentRoomZoomed) {
    int startXBox = totalConsoleWidth * 2 / 5;
    int endXBox = totalConsoleWidth * 3 / 5;
    int startYBox = (totalConsoleHeight * 1 / 3) + 1;
    int endYBox = totalConsoleHeight - 1;
    int startXTitle = (totalConsoleWidth - artWidth/3) / 2;
    int startYTitle = (startYBox - artHeight) / 2;

    std::vector<std::string> options = {"CONTINUE", "LOAD GAME", "CONTROLS", "SAVE AND EXIT"};

    int selectedIndex = renderOptionsBox(startXBox, endXBox, startYBox, endYBox, options);

    switch (selectedIndex) {
        case 0: 
            // New Game selected, run the intro
            saveGame(currentRoomZoomed);
            clearWholeScreen();
            break;

        case 1: {
            std::vector<std::string> saves = getSaveFilesList();
            if (saves.empty()) {
                std::string noSaves = "No Save Game Data Found";
                renderBox(startXBox, endXBox, startYBox, endYBox, noSaves, FALSE, FALSE, FALSE);
                Sleep(1000);
                clearWholeScreen();
                break;
            }
            int selectedSave = renderOptionsBox(startXBox, endXBox, startYBox, endYBox, saves);
            saveFileName = saves[selectedSave];

            loadGame(saveFileName);
            clearWholeScreen();
            switch (roomNumber) {
                case 0: {
                    std::string noSaves = "XXXXXXXXXXXXXXXXX";
                    Sleep(1000);
                    renderBox(startXBox, endXBox, startYBox, endYBox, noSaves, FALSE, FALSE, FALSE);
                    break;
                }
                case 1:
                    runAnthony();
                    break;
                case 2:
                    runOscar();
                    break;
                case 3:
                    runLachlan();
                    break;
                case 4:
                    //runCallum();
                    break;
            }
        }
            break;
        
        case 2: {
            clearWholeScreen();
            renderCenteredArt(art, artWidth, artHeight);
            std::string instructions =  
            "Left and Right Arrow Keys = change view of walls in room\n"  
            "Up and Down Arrow Keys = move between options in menus\n" 
            "Enter = input values or select options in menus\n" 
            "Esc = pause the game/Exit the pause menu";
            renderBox(totalConsoleWidth * 1 / 5, totalConsoleWidth * 4 / 5, (totalConsoleHeight * 1 / 3) + 1, (totalConsoleHeight * 2 / 3) + 1 , instructions, TRUE, TRUE, TRUE);
            while (input != 27) {processInput();}
            clearWholeScreen();
            break;
        }
        case 3:
            // Exit selected
            // TO DO: implement saving
            saveGame(currentRoomZoomed);
            running = false;
            break;       

        default:
            std::string noSaves = "Broke";
            Sleep(1000);
            renderBox(startXBox, endXBox, startYBox, endYBox, noSaves, FALSE, FALSE, FALSE);
            break;
    }
}
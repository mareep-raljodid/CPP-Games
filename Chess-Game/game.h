#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "board.h"

using namespace std;

class Game {
  private:
    Board board;
    bool hasWon;
    /* Function Name: intro
     *
     * Function Description:
     * This function introduces the game to the user and decides whether to
     * use unicode chess pieces.
     *
     * Parameters:
     * N/A
     *
     * return value:
     * N/A
     */
    void intro();
    /* Function Name: loop
     *
     * Function Description:
     * This function loops through each players turn, getting and parsing each
     * command.
     *
     * Parameters:
     * N/A
     *
     * return value:
     * N/A
     */
    void loop();
    /* Function Name: help
     *
     * Function Description:
     * This function displays the available commands to the user
     *
     * Parameters:
     * N/A
     *
     * return value:
     * N/A
     */
    void help();
    /* Function Name: parseInput
     *
     * Function Description:
     * This function obtains input and determines what board function to call
     * or what else to do.
     *
     * Parameters:
     * The color parameter is a 'b' or 'w' representing the color of the player.
     *
     * return value:
     * Returns true if the player forfeits, false otherwise.
     */
    bool parseInput(char color);
    /* Function Name: getInput
     *
     * Function Description:
     * This function obtains input from cin and splits it into two words.
     * This function is borrowed from project 1.
     *
     * Parameters:
     * N/A
     *
     * return value:
     * Returns input as a vector of the words input.
     */
    vector<string> getInput();
  public:
    Game();
    /* Function Name: start
     *
     * Function Description:
     * This function runs through the intro and help and then starts the loop.
     *
     * Parameters:
     * N/A
     *
     * return value:
     * N/A
     */
    void start();
};

#endif

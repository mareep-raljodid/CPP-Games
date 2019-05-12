#include <iostream>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include "game.h"
#include "board.h"

using namespace std;

Game::Game() {
  Game::hasWon = false;
}

void Game::start() {
  intro();
  help();
  loop();
}

void Game::intro() {
  char ascii;
  cout << "Welcome to Chess!" << endl;
  cout << "Written by Rajdeep Bandopadhyay and William Leithauser" << endl;
  cout << endl;
  cout << "This is a two-player game. Each player will take turns" << endl;
  cout << "making his move." << endl << endl;
  cout << "Do you want to use unicode chess icons? (y/n)" << endl;
  cin >> ascii;
  Game::board.setAscii(!(ascii == 'y'));
  cout << endl;
}

void Game::help() {
  cout << "Commands:" << endl;
  cout << "=========" << endl;
  cout << endl;
  cout << "------------------------------------------------------------------" <<endl;
  cout << "move <expression>: make a move" << endl;
  cout << "      Expression is of the form initial space followed by" << endl;
  cout << "      destination space. For example, \"move B3C5\" will move" << endl;
  cout << "      the pice at B3 to C5." << endl;
  cout << endl;
  cout << "------------------------------------------------------------------" <<endl;
  cout << "castle <direction>: performs a castle" << endl;
  cout << "        Direction must be \"left\" or \"right\"." << endl;
  cout << endl;
  cout << "------------------------------------------------------------------" <<endl;
  cout << "forfeit: forfeits the game." << endl << endl;
  cout << endl;
  cout << "------------------------------------------------------------------" <<endl;
}

void Game::loop() {
  while (!Game::hasWon) {
    system("clear");
    system("CLS");
    Game::help();
    Game::board.print();
    if (Game::board.check('w', false))
      cout << "You are in check." << endl;
    cout << "Enter command white:" << endl;
    if (parseInput('w'))
      return;
    system("clear");
    system("CLS");
    Game::help();
    Game::board.print();
    if (Game::board.check('b', false))
      cout << "You are in check." << endl;
    cout << "Enter command black:" << endl;
    parseInput('b');
  }
}

bool Game::parseInput(char color) {
  vector<string> inp;
  inp = getInput();
  bool validCommand;
  bool valMove;
  bool firstLoop = true;
  do {
    validCommand = true;
    if (inp.at(0) == "help") {
      help();
    } else if (inp.at(0) == "forfeit") {
      cout << ((color == 'w') ? "white" : "black") << " has forefeit." << endl;
      Game::hasWon = true;
      return true;
    } else if (inp.at(0) == "move") {
      int from[2];
      int to[2];
      do {
        from[0] = ((inp.at(1)).at(0) - 97);
        from[1] = ((inp.at(1)).at(1) - 49);
        to[0]   = ((inp.at(1)).at(2) - 97);
        to[1]   = ((inp.at(1)).at(3) - 49);
        valMove = Game::board.validMove(from[1], from[0], to[1], to[0], color);
        if (valMove) {
          Game::board.move(from[1], from[0], to[1], to[0]);
        } else {
          cout << "Invalid move. Enter new command." << endl;
          inp = getInput();
        }
      } while (!valMove);
    } else if (inp.at(0) == "castle") {
      char ser=inp.at(1).at(0);
      if (!Game::board.castle(color, ser)) {
        cout << "Invalid castle. Enter new command." << endl;
        validCommand = false;
        inp = getInput();
      }
    } else {
      validCommand = false;
      if (!firstLoop)
        cout << "Invalid command. Enter new command." << endl;
      inp = getInput();
    }
  } while(!validCommand);
  return false;
}

vector<string> Game::getInput() {
  bool isError;
  vector<string> inputs;
  int firstSpace;
  do {
    isError = false;
    inputs.resize(0);
    string inLine;
    cout << ">";
    getline(cin, inLine);
    for (int i = 0; i < inLine.length(); i++) {
      if (!(isalnum(inLine.at(i)) || inLine.at(i) == ' ')) {
        cout << "Error: Only include letters and spaces." << endl;
        cout << endl;
        isError = true;
        break;
      }
      inLine.at(i) = tolower(inLine.at(i));
    }
    firstSpace = inLine.find(' ');
    if (firstSpace == string::npos) {
      inputs.push_back(inLine);
    } else {
      inputs.push_back(inLine.substr(0, firstSpace));
      inputs.push_back(inLine.substr(firstSpace + 1, inLine.length() - 1));
    }
    if ((inputs.size() - 1) && inputs.at(1).find(' ') != string::npos) {
      cout << "Error: Only include one space per command." << endl;
      cout << endl;
      isError = true;
    }
  } while (isError);
  return inputs;
}

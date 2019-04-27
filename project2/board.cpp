#include <iostream>
#include <string.h>
#include <cctype>
#include <cmath>
#include <stdlib.h>
#include "board.h"
using namespace std;

Board::Board() {
  bool running = true;
  bool isAscii = false;
  Board::newBoard();
  rwrook = lwrook = wking = rbrook = lbrook = bking = true;
}

void Board::newBoard() {
  for(int y = 0; y < BOARD_SIZE; y++)
    for(int x = 0; x < BOARD_SIZE; x++)
      board[x][y] = board2[x][y] = startup[y][x];
}

void Board::setPiece(int piece) {
  string ck;

  switch(piece) {
    case rook:
      ck = Board::isAscii ? " BR  " : "  ♖  ";
      break;
    case bishop:
      ck = Board::isAscii ? " BB  " : "  ♗  ";
      break;
    case knight:
      ck = Board::isAscii ? " BN  " : "  ♘  ";
      break;
    case king:
      ck = Board::isAscii ? " BK  " : "  ♔  ";
      break;
    case queen:
      ck = Board::isAscii ? " BQ  " : "  ♕  ";
      break;
    case pawn:
      ck = Board::isAscii ? " BP  " : "  ♙  ";
      break;
    case -rook:
      ck = Board::isAscii ? " WR  " : "  ♜  ";
      break;
    case -bishop:
      ck = Board::isAscii ? " WB  " : "  ♝  ";
      break;
    case -knight:
      ck = Board::isAscii ? " WN  " : "  ♞  ";
      break;
    case -king:
      ck = Board::isAscii ? " WK  " : "  ♚  ";
      break;
    case -queen:
      ck = Board::isAscii ? " WQ  " : "  ♛  ";
      break;
    case -pawn:
      ck = Board::isAscii ? " WP  " : "  ♟  ";
      break;
    case 0:
    default:
      ck = "  ☐  ";
      break;
  }
	
  cout << ck;
}

void Board::print() {
  cout << "  ";
  for(int x = 0; x < BOARD_SIZE; x++)
    cout << "|  " << char(65 + x) << "  ";
  cout << endl;
  cout << "-.-----------------------------------------------" << endl;
  for(int y = 0; y < BOARD_SIZE; y++) {
    cout << (y + 1) << "|";
    for(int x = 0; x < BOARD_SIZE; x++) {
      cout << " ";
      setPiece(board[x][y]);
    }
    cout << endl;
    cout << " |" << endl;
  }
  cout << endl;
}

string toLowercase(string str) {
  string upstr;
  for(int i = 0; i < str.length(); i++)
    upstr.push_back(tolower(str[i]));
  return upstr;
}

void Board::move(int fromX, int fromY, int toX, int toY) {
  int piece = board[fromY][fromX];
  int dpiece = board[toY][toX];
  board[toY][toX] = piece;
  board[fromY][fromX] = 0;
  if (((fromY == 0) && (fromX == 0) && (piece == rook)) || 
      ((toY == 0) && (toX == 0) && (dpiece == rook)))
    lbrook = false;
  if (((fromY == 7) && (fromX == 0) && (piece == rook)) || 
      ((toY == 7) && (toX == 0) && (dpiece == rook)))
    rbrook = false;
  if (((fromY == 0) && (fromX == 7) && (piece == -rook)) || 
      ((toY == 0) && (toX == 7) && (dpiece == -rook)))
    lwrook = false;
  if (((fromY == 7) && (fromX == 7) && (piece == -rook)) || 
      ((toY == 7) && (toX == 7) && (dpiece == -rook)))
    rwrook = false;
  if (piece == king)
    bking = false;
  if (piece == -king)
    wking = false;
}

// Character s is the required side to which the user is castling and c is the
// color of the piece, and moved is the int which stores if king or rook is previously
bool Board::castle(char c, char s) {
  if (c == 'b') {
    if (s == 'r') {
      if ((board[4][0] == king) && (board[7][0] == rook) && rbrook &&
          bking && (board[5][0] == 0) && (board[6][0] == 0)) {
        cout << "You castled with the right Rook." << endl;
        board[4][0] = 0;
        board[5][0] = rook;
        board[6][0] = king;
        board[7][0] = 0;
        rbrook = false;
        bking = false;
        return true;
      }
    }
    if (s == 'l'){
      if ((board[4][0] == king) && (board[0][0] == rook) && lbrook && bking
          && (board[1][0] == 0) && (board[2][0] == 0) && (board[3][0] == 0)) {
        cout << "You castled with the left Rook." << endl;
        board[0][0] = 0;
        board[1][0] = 0;
        board[2][0] = king;
        board[3][0] = rook;
        board[4][0] = 0;
        lbrook = false;
        bking = false;
        return true;
      }
    }
  }
  if (c == 'w') {
    if (s == 'r') {
      if ((board[4][7] == -king) && (board[7][7] == -rook) && rwrook &&
          wking && (board[5][7] == 0) && (board[6][7] == 0)) {
        cout << "You castled with the right Rook." << endl;
        board[4][7] = 0;
        board[5][7] = -rook;
        board[6][7] = -king;
        board[7][7] = 0;
        rwrook = false;
        wking = false;
        return true;
      }
    }
    if (s == 'l') {
      if ((board[4][7] == -king) && (board[0][7] == -rook) && lwrook && wking
          && (board[1][7] == 0) && (board[2][7] == 0) && (board[3][7] == 0)) {
        cout << "You castled with the left Rook." << endl;
        board[0][7] = 0;
        board[1][7] = 0;
        board[2][7] = -king;
        board[3][7] = -rook;
        board[4][7] = 0;
        lwrook = false;
        wking = false;
        return true;
      }
    }
  }
}

bool Board::validMove(int fromX, int fromY, int toX, int toY, char color) {
  // Check if move is within the board
  if ((fromX > 7) || (fromX < 0) || (fromY > 7) || (fromY < 0) ||
        (toX > 7) ||   (toX < 0) ||   (toY > 7) ||   (toY < 0)) {
    cout << "Outside boundaries" << endl;
    return false;
  }
  // Check if move is to a different space
  if ((fromX == toX) && (fromY == toY)) {
    cout << "Destination same as origin" << endl;
    return false;
  }
  // Check if origin space is an actual piece
  if (board[fromY][fromX] == 0) {
    cout << "Not a piece" << endl;
    return false;
  }
  // Check if piece color matches player color
  //this is just to show you
  if (((board[fromY][fromX] > 0) && (color == 'w')) || 
      ((board[fromY][fromX] < 0) && (color == 'b'))) {
    cout << "Incorrect color piece" << endl;
    return false;
  }
  // Check if destination piece matches player color  
  if (((board[toY][toX] > 0) && (color == 'b')) || 
      ((board[toY][toX] < 0) && (color == 'w'))) {
    cout << "Destination piece same as player piece" << endl;
    return false;
  }
  // Individual piece rules
  switch (abs(board[fromY][fromX])) {
    case rook:
      // Straight lines
      if ((toX != fromX) && (toY != fromY))
       return false;
      // No pieces in the way
      if ((toX == fromX) && (toY > fromY))
        for (int i = (fromY + 1); i < toY; i++)
          if (board[i][fromX] != 0)
            return false;
      if ((toY == fromY) && (toX > fromX))
        for (int i = (fromX + 1); i < toX; i++)
          if (board[fromY][i] != 0)
            return false;
      if ((toX == fromX) && (toY < fromY))
        for (int i = (fromY - 1); i > toY; i--)
          if (board[i][fromX] != 0)
            return false;
      if ((toY == fromY) && (toX < fromX))
        for (int i = (fromX - 1); i > toX; i--)
          if (board[fromY][i] != 0)
            return false;
      break;
    case bishop:
      // Diagonals
      if (abs(toY - fromY) != abs(toX - fromX))
        return false;
      // No pieces in the way
      if ((toY > fromY) && (toX > fromX))
        for (int i = 1; i < abs(toY - fromY); i++)
          if (board[fromY + i][fromX + i] != 0)
            return false;
      if ((toY > fromY) && (toX < fromX))
        for (int i = 1; i < abs(toY - fromY); i++)
          if (board[fromY + i][fromX - i] != 0)
            return false;
      if ((toY < fromY) && (toX > fromX))
        for (int i = 1; i < abs(toY - fromY); i++)
          if (board[fromY - i][fromX + i] != 0)
            return false;
      if ((toY < fromY) && (toX < fromX))
        for (int i = 1; i < abs(toY - fromY); i++)
          if (board[fromY - i][fromX - i] != 0)
            return false;
      break;
    case pawn:
      if ((color == 'w') && (toX > fromX))
        return false;
      if ((color == 'b') && (toX < fromX))
        return false;
      if (board[toY][toX] != 0)
        if (!((abs(toY - fromY) == 1) && (abs(toX - fromX) == 1)))
          return false;
      if (toY != fromY)
        return false;
      if (abs(toX - fromX) > 2)
        return false;
      if ((abs(toX - fromX) == 2) && (color == 'w') && (fromX != 6))
        return false;
      if ((abs(toX - fromX) == 2) && (color == 'b') && (fromX != 1))
        return false;
      break;
    case knight:
      if (!(((abs(toY - fromY) == 2) && (abs(toX - fromX) == 1)) ||
            ((abs(toY - fromY) == 1) && (abs(toX - fromX) == 2))))
        return false;
      break;
    case queen:
      // Straight line
      if ((abs(toY - fromY) != abs(toX - fromX)) &&
          ((toX != fromX) && (toY != fromY)))
        return false;
      // No pieces in the way
      if ((toX == fromX) && (toY > fromY))
        for (int i = (fromY + 1); i < toY; i++)
          if (board[i][fromX] != 0)
            return false;
      if ((toY == fromY) && (toX > fromX))
        for (int i = (fromX + 1); i < toX; i++)
          if (board[fromY][i] != 0)
            return false;
      if ((toX == fromX) && (toY < fromY))
        for (int i = (fromY - 1); i > toY; i--)
          if (board[i][fromX] != 0)
            return false;
      if ((toY == fromY) && (toX < fromX))
        for (int i = (fromX - 1); i > toX; i--)
          if (board[fromY][i] != 0)
            return false;
      if ((toY > fromY) && (toX > fromX))
        for (int i = 1; i < abs(toY - fromY); i++)
          if (board[fromY + i][fromX + i] != 0)
            return false;
      if ((toY > fromY) && (toX < fromX))
        for (int i = 1; i < abs(toY - fromY); i++)
          if (board[fromY + i][fromX - i] != 0)
            return false;
      if ((toY < fromY) && (toX > fromX))
        for (int i = 1; i < abs(toY - fromY); i++)
          if (board[fromY - i][fromX + i] != 0)
            return false;
      if ((toY < fromY) && (toX < fromX))
        for (int i = 1; i < abs(toY - fromY); i++)
          if (board[fromY - i][fromX - i] != 0)
            return false;
      break;
    case king:
      if ((abs(toY - fromY) > 1) || (abs(toX - fromX) > 1))
        return false;
    default:
      break;
  }
  copyBoard();
  int piece = board2[fromY][fromX];
  board2[toY][toX] = piece;
  board2[fromY][fromX] = 0;
  if (check(color, true)) {
    cout << "That move would put you in check" << endl;
    return false;
  }
  return true;
}

void Board::setAscii(bool b) {
  isAscii = b;
}

void Board::copyBoard() {
  for (int i = 0; i < BOARD_SIZE; i++)
    for (int j = 0; j < BOARD_SIZE; j++)
      board2[i][j] = board[i][j];
}

bool Board::check(char color, bool second) {
  //cout << "Checking for check..." << color << endl;
  int tempX;
  int tempY;
  if (!second)
    copyBoard();
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (((board2[i][j] == -king) && (color == 'w')) ||
          ((board2[i][j] == king) && (color == 'b'))) {
        tempX = i;
        tempY = j;
      }
    }
  }
  //cout << "x:" << tempX << " " << "y:" << endl << tempY << endl;
  if (color == 'w') {
    for (int i = (tempX + 1); i < 8; i++) {
      if (board2[i][tempY] != 0) {
        if ((board2[i][tempY] == rook) || (board2[i][tempY] == queen))
          return true;
        if ((board2[i][tempY] == king) && (i == (tempX + 1)))
          return true;
        break;
      }
      //cout << "ws1 " << i << endl;
    }
    for (int i = (tempX - 1); i >= 0; i--) {
      if (board2[i][tempY] != 0) {
        if ((board2[i][tempY] == rook) || (board2[i][tempY] == queen))
          return true;
        if ((board2[i][tempY] == king) && (i == (tempX - 1)))
          return true;
        break;
      }
      //cout << "ws2 " << i << endl;
    }
    for (int i = (tempY + 1); i < 8; i++) {
      if (board2[tempX][i] != 0) {
        if ((board2[tempX][i] == rook) || (board2[tempX][i] == queen))
          return true;
        if ((board2[tempX][i] == king) && (i == (tempY + 1)))
          return true;
        break;
      }
      //cout << "ws3 " << i << endl;
    }
    for (int i = (tempY - 1); i >= 0; i--) {
      if (board2[tempX][i] != 0) {
        if ((board2[tempX][i] == rook) || (board2[tempX][i] == queen))
          return true;
        if ((board2[tempX][i] == king) && (i == (tempY - 1)))
          return true;
        break;
      }
      //cout << "ws4 " << i << endl;
    }
    for (int i = 1; i < 8; i++) {
      if (((tempX + i) > 7) || ((tempY + i) > 7)) break;
      if (board2[tempX + i][tempY + i] != 0) {
        if ((board2[tempX + i][tempY + i] == bishop) ||
            (board2[tempX + i][tempY + i] == queen))
          return true;
        if ((board2[tempX + i][tempY + i] == king) && (i == 1))
          return true;
        break;
      }
      //cout << "wd1 " << i << endl;
    }
    for (int i = 1; i < 8; i++) {
      if (((tempX + i) > 7) || ((tempY - i) < 0)) break;
      if (board2[tempX + i][tempY - i] != 0) {
        if ((board2[tempX + i][tempY - i] == bishop) ||
            (board2[tempX + i][tempY - i] == queen))
          return true;
        if ((board2[tempX + i][tempY - i] == king) && (i == 1))
          return true;
        if ((board2[tempX + i][tempY - i] == pawn) && (i == 1))
          return true;
        break;
      }
      //cout << "wd2 " << i << endl;
    }
    for (int i = 1; i < 8; i++) {
      if (((tempX - i) < 0) || ((tempY + i) > 7)) break;
      if (board2[tempX - i][tempY + i] != 0) {
        if ((board2[tempX - i][tempY + i] == bishop) ||
            (board2[tempX - i][tempY + i] == queen))
          return true;
        if ((board2[tempX - i][tempY + i] == king) && (i == 1))
          return true;
        break;
      }
      //cout << "wd3 " << i << endl;
    }
    for (int i = 1; i < 8; i++) {
      if (((tempX - i) < 0) || ((tempY - i) < 0)) break;
      if (board2[tempX - i][tempY - i] != 0) {
        if ((board2[tempX - i][tempY - i] == bishop) ||
            (board2[tempX - i][tempY - i] == queen))
          return true;
        if ((board2[tempX - i][tempY - i] == king) && (i == 1))
          return true;
        if ((board2[tempX - i][tempY - i] == pawn) && (i == 1))
          return true;
        break;
      }
      //cout << "wd4 " << i << endl;
    }
  } else {
    //cout << "starting" << endl;
    for (int i = (tempX + 1); i < 8; i++) {
      if (board2[i][tempY] != 0) {
        if ((board2[i][tempY] == -rook) || (board2[i][tempY] == -queen))
          return true;
        if ((board2[i][tempY] == -king) && (i == (tempX + 1)))
          return true;
        break;
      }
      //cout << "bs1 " << i << endl;
    }
    //cout << "through bs1" << endl;
    for (int i = (tempX - 1); i >= 0; i--) {
      if (board2[i][tempY] != 0) {
        if ((board2[i][tempY] == -rook) || (board2[i][tempY] == -queen))
          return true;
        if ((board2[i][tempY] == -king) && (i == (tempX - 1)))
          return true;
        break;
      }
      //cout << "bs2 " << i << endl;
    }
    //cout << "through bs2" << endl;
    for (int i = (tempY + 1); i < 8; i++) {
      if (board2[tempX][i] != 0) {
        if ((board2[tempX][i] == -rook) || (board2[tempX][i] == -queen))
          return true;
        if ((board2[tempX][i] == -king) && (i == (tempY + 1)))
          return true;
        break;
      }
      //cout << "bs3 " << i << endl;
    }
    //cout << "through bs3" << endl;
    for (int i = (tempY - 1); i >= 0; i--) {
      if (board2[tempX][i] != 0) {
        if ((board2[tempX][i] == -rook) || (board2[tempX][i] == -queen))
          return true;
        if ((board2[tempX][i] == -king) && (i == (tempY - 1)))
          return true;
        break;
      }
      //cout << "bs4 " << i << endl;
    }
    //cout << "through bs4" << endl;
    for (int i = 1; i < 8; i++) {
      if (((tempX + i) > 7) || ((tempY + i) > 7)) break;
      if (board2[tempX + i][tempY + i] != 0) {
        if ((board2[tempX + i][tempY + i] == -bishop) ||
            (board2[tempX + i][tempY + i] == -queen))
          return true;
        if ((board2[tempX + i][tempY + i] == -king) && (i == 1))
          return true;
        if ((board2[tempX + i][tempY + i] == -pawn) && (i == 1))
          return true;
        break;
      }
      //cout << "bd1 " << i << endl;
    }
    //cout << "through bd1" << endl;
    for (int i = 1; i < 8; i++) {
      if (((tempX + i) > 7) || ((tempY - i) < 0)) break;
      if (board2[tempX + i][tempY - i] != 0) {
        if ((board2[tempX + i][tempY - i] == -bishop) ||
            (board2[tempX + i][tempY - i] == -queen))
          return true;
        if ((board2[tempX + i][tempY - i] == -king) && (i == 1))
          return true;
        break;
      }
      //cout << "bd2 " << i << endl;
    }
    //cout << "through bd2" << endl;
    for (int i = 1; i < 8; i++) {
      if (((tempX - i) < 0) || ((tempY + i) > 7)) break;
      if (board2[tempX - i][tempY + i] != 0) {
        if ((board2[tempX - i][tempY + i] == -bishop) ||
            (board2[tempX - i][tempY + i] == -queen))
          return true;
        if ((board2[tempX - i][tempY + i] == -king) && (i == 1))
          return true;
        if ((board2[tempX - i][tempY + i] == -pawn) && (i == 1))
          return true;
        break;
      }
      //cout << "bd3 " << i << endl;
    }
    //cout << "through bd3" << endl;
    for (int i = 1; i < 8; i++) {
      if (((tempX - i) < 0) || ((tempY - i) < 0)) break;
      if (board2[tempX - i][tempY - i] != 0) {
        if ((board2[tempX - i][tempY - i] == -bishop) ||
            (board2[tempX - i][tempY - i] == -queen))
          return true;
        if ((board2[tempX - i][tempY - i] == -king) && (i == 1))
          return true;
        break;
      }
      //cout << "bd4 " << i << endl;
    }
    //cout << "through bd4" << endl;
  }
  return false;
}


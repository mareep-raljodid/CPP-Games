#ifndef BOARD_H
#define BOARD_H
#define BOARD_SIZE 8

const int pawn = 100;
const int bishop = 305;
const int knight = 300;
const int rook = 500;
const int queen = 900;
const int king = 2000;//values are subject to change

class Board {
  public:
    int board[BOARD_SIZE][BOARD_SIZE];
    int board2[BOARD_SIZE][BOARD_SIZE];
    const int startup[8][8] = {rook, knight, bishop, 
    queen, king, bishop, knight, rook, pawn, pawn, pawn,
    pawn, pawn, pawn, pawn, pawn, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn,
    -pawn, -pawn, -rook, -knight, -bishop, -queen, -king, 
    -bishop, -knight, -rook};
    bool isAscii;
    bool rwrook;
    bool lwrook;
    bool wking;
    bool rbrook;
    bool lbrook;
    bool bking;

  public:
    Board();
    /* Function Name: newBoard
     *
     * Function Description:
     * This function initializes the board.
     *
     * Parameters:
     * N/A
     *
     * return value:
     * N/A
     */
    void newBoard();
    /* Function Name: print
     *
     * Function Description:
     * This function displays the board to the user.
     *
     * Parameters:
     * N/A
     *
     * return value:
     * N/A
     */
    void print();
    /* Function Name: validMove
     *
     * Function Description:
     * This function determines if the selected move is valid, including
     * checking if it will put the player in check.
     *
     * Parameters:
     * fromY is the initial y coordinate of the piece
     * fromX is the initial x coordinate of the piece
     * toY is the final y coordinate of the piece
     * toX is the final x coordinate of the piece
     * color is the color, 'w' for white or 'b' for black
     * 
     * return value:
     * Returns true if the move was valid, false otherwise.
     */
    bool validMove(int fromY, int fromX, int toY, int toX, char color);
    /* Function Name: validMove
     *
     * Function Description:
     * This function moves a piece on the board.
     *
     * Parameters:
     * fromY is the initial y coordinate of the piece
     * fromX is the initial x coordinate of the piece
     * toY is the final y coordinate of the piece
     * toX is the final x coordinate of the piece
     * 
     * return value:
     * Returns true if the move was valid, false otherwise.
     */
    void move(int fromY, int fromX, int toY, int toX);
    /* Function Name: castle
     *
     * Function Description:
     * This function determines if it is possible to castle, and if so,
     * it castles.
     *
     * Parameters:
     * s is the side to castle to, 'l' for left and 'r' for right.
     *
     * return value:
     * Returns true if the castle was successful, false otherwise.
     */
    bool castle(char s, char c);
    /* Function Name: setPiece
     *
     * Function Description:
     * This function turns an integer piece into something that can be output
     * to cout.
     *
     * Parameters:
     * Takes the integer value of the piece.
     *
     * return value:
     * N/A
     */
    void setPiece(int);
    /* Function Name: setAscii
     *
     * Function Description:
     * This function sets whether ASCII is used to display the board to the
     * user or if unicode chess pieces are used instead.
     *
     * Parameters:
     * b is whether or not to use ASCII
     *
     * return value:
     * N/A
     */
    void setAscii(bool b);
    /* Function Name: copyBoard
     *
     * Function Description:
     * This function copies the main board to a second test board. This is
     * used to test theoretical moves, for example to see if a future move
     * would place the player in check.
     *
     * Parameters:
     * N/A
     *
     * return value:
     * N/A
     */
    void copyBoard();
    /* Function Name: check
     *
     * Function Description:
     * This function determines if the player is in check or not.
     *
     * Parameters:
     * color is 'w' for white or 'b' for black
     * second is true if checking the secondary test board and false when
     *   testing the main board.
     *
     * return value:
     * Returns true if in check, false otherwise.
     */
    bool check(char color, bool second);
};
#endif 

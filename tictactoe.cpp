/*
  Tic-Tac-Toe Game

  Description:
  This C++ program implements a simple console-based Tic-Tac-Toe game where two players ('X' and 'O') take turns to make a move. The program displays the current state of the board after each move and checks for a winner or a draw.

  Global Variables:
  - x, y: Variables to store the horizontal and vertical positions on the board.
  - CH, CV: Variables used to check the validity of the input positions.
  - memo: Variable to fill in 'X' or 'O' on the board.
  - board: 3x3 array representing the Tic-Tac-Toe board.

  Functions:
  - displayBoard(): Function to display the current state of the Tic-Tac-Toe board.
  - displayWinner(): Function to display the winner or declare a draw.
  - check(): Function to check for a winner or a draw.
  - fill(): Function to fill the board with initial values (either '-' or numbers).
  - main(): The main function where the game loop and user input are handled.

  Author: Aleko Khomasuridze
  Date: September 27, 2023
*/

#include<iostream>

using namespace std;

// Global Variables
int x = 0, y = 0, CH, CV; // variables for x, y vertical, horizontal values
char memo;  // variable for filling in x, y on board
char board[3][3]; // 3x3 board 

// Function to display the current state of the board
void displayBoard(){
  cout<<"\n\n\n  --- --- ---\n";  // horizontal border of board
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout<<" | "<<board[i][j];  // vertical border of board with values
    }
    cout<<" |\n  --- --- ---\n";
  }
  cout<<"\n\n";
}

// Function to declare the winner or a draw
void displayWinner(char playerVal){
  cout<<"\n\n\n";
  for(int i = 0; i < 60; i++){  // top border for winner
    cout<<"#";
  }
  cout<<"\n\n";
  if(playerVal == 'D') cout<<"\t\t\t\t\t draw!"; // if it is a draw 
  else cout<<"\t\t\t"<<playerVal<<" won the game!";  // if 'X' or 'O' won
  cout<<"\n\n";
  for(int i = 0; i < 60; i++){  // bottom border for winner
    cout<<"#";
  }
  cout<<"\n\n\n";
}

// Function to check for a winner or a draw
char check(){
  if(board[0][0] == 'X' and board[0][1] == 'X' and board[0][2] == 'X'     //
  or board[1][0] == 'X' and board[1][1] == 'X' and board[1][2] == 'X'		//
  or board[2][0] == 'X' and board[2][1] == 'X' and board[2][2] == 'X'		//
  or board[0][0] == 'X' and board[1][0] == 'X' and board[2][0] == 'X'		//   check win combinations for 'X'
  or board[0][1] == 'X' and board[1][1] == 'X' and board[2][1] == 'X'		//
  or board[0][2] == 'X' and board[1][2] == 'X' and board[2][2] == 'X'		//
  or board[0][0] == 'X' and board[1][1] == 'X' and board[2][2] == 'X'		//
  or board[0][2] == 'X' and board[1][1] == 'X' and board[2][0] == 'X'){	//
    return 'X';   // declare 'X' as winner 
  }
  else if(board[0][0] == 'O' and board[0][1] == 'O' and board[0][2] == 'O'	//
       or board[1][0] == 'O' and board[1][1] == 'O' and board[1][2] == 'O'	//
       or board[2][0] == 'O' and board[2][1] == 'O' and board[2][2] == 'O'	//
       or board[0][0] == 'O' and board[1][0] == 'O' and board[2][0] == 'O'	//	 check win combinations for 'O'
       or board[0][1] == 'O' and board[1][1] == 'O' and board[2][1] == 'O'	//
       or board[0][2] == 'O' and board[1][2] == 'O' and board[2][2] == 'O'	//
       or board[0][0] == 'O' and board[1][1] == 'O' and board[2][2] == 'O'	//
       or board[0][2] == 'O' and board[1][1] == 'O' and board[2][0] == 'O'){  //
    return 'O';   // declare 'O' as winner 
  }
  else
    return 'D';   // it is draw 
}

// Function to fill the board with initial values
void fill(string type){
  if(type == "-"){   // fill with '-'
    memo = '-';
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        board[i][j] = '-';
      }
    }
  }else if(type == "numbers"){  // fill with numbers
    int change = 0;
    memo = '1';
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        board[i][j] = 49 + change;
        change += 3;
      }
    }
  }
}

// Main function
int main(){
  fill("-");  // fill board with '-'

  while(true){  // loop the action
    CV = y == 0 || y == 1 || y == 2;
    CH = x == 0 || x == 1 || x == 2;

    // Check for a winner or draw
    if(check() == 'O'){
      displayWinner('O');
      break;
    }else if(check() == 'X'){
      displayWinner('X');
      break;
    }else if(CV and CH and check() == 'D' and board[x][y] == '-'){
      board[x][y] = memo; 
      displayBoard();
      if(memo == 'O') memo = 'X';
      else memo = 'O';
    }else if(!(CH and CV) and board[x][y] != '-'){
      cout<<"\n\nError Please Try Again! \n\n";
    }

    // Get user input for the next move
    cout << memo << " Enter horizontal position: ";
    cin >> x;
    cout << memo << " Enter vertical position: ";
    cin >> y;	
    cout << "\n" << memo << " --> [" << x << ":" << y << "]\n";
  }

  return 0;
}

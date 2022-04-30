#include <iostream>
#include <time.h>
#include <algorithm>
#include <windows.h>
using namespace std;


#define COMPUTERMOVE 'O'
#define HUMANMOVE 'X'

void displayBoard(char board[]);
bool rangeCorrect(int cell);
bool cellIsEmpty(int cell, char board[]);
void changeTurn(char& turn);
bool three(char turn, char board[]);
bool threeInARow(char turn, char board[]);
bool threeInAColumn(char turn, char board[]);
bool threeInADiagonal(char turn, char board[]);
int getint();
int mode1(); 
int mode2();
void choose_mood();
void delay(int number_of_seconds);
//define linked list

struct Node {
	int moveNumber;//number of cell
	char board[9];//like matrix 3*3
	Node* nextPtr;
};

void displayList(Node* head);


int main()
{
	choose_mood();
	

}

int mode1()
{
	system("Color B5");
	cout << "\n go a head player X\n ";
	char board[9];
	//initializing board
	for (int i = 0; i < 9; i++)
		board[i] = ' ';

	Node* head = NULL;   // head of linked list 
	Node* tempPtr;

	int moveNumber = 0;
	char turn = 'X';
	int cell = 0;

	while (moveNumber < 9) {
		displayBoard(board);
		cout << "*****************************" << endl;
		cout << "Move number: " << moveNumber << endl;
		cout << "TURN: " << turn << " make your move: ";
		cell = getint(); //this is the simple version. only input numbers here. does not check non-numeric characters..
						 //is input correct?
		if (rangeCorrect(cell)) { //checking if inside the range 1-9
			if (cellIsEmpty(cell - 1, board)) { //checking if cell is empty. subtracting 1, because array starts from 0.
				board[cell - 1] = turn;//storing the move in the array
				if (three(turn, board)) {//checking if there are three in a row or column or diagonal
					displayBoard(board);
					system("Color E4");
					cout << "\nCongratulations player " << turn << " You win!!";
					changeTurn(turn);
					cout << "\nGood luck next time player " << turn << " good effort ";
					cout << "\n the game will terminate in 4 seconds ";

					delay(4);
					exit(1);
					//cin >> cell; //to stop execution on windows 
					return 1;
				}

				//creating a new Node, filling its fields and adding to the list.
				tempPtr = new Node;
				// Insert at head of list 
				tempPtr->moveNumber = moveNumber; //copying moveNumber inside the node
				for (int i = 0; i < 9; i++) { //copying the elements of the board inside the board in the node
					tempPtr->board[i] = board[i];
				}
				tempPtr->nextPtr = head; //the pointer of the node points to the first element of the list
				head = tempPtr; //the head points to the new node just created
				moveNumber++; //preparing for next move.
				changeTurn(turn);//changing the turn to the next player.

			}
			else { //cell was full
				cout << "Sorry...cell " << cell << " has already been used, try again: " << endl;
			}
		}
		else {
			cout << "Sorry...cell " << cell << " is outside the range 1-9, try again: or  uccorrect input please enter valid number" << endl;
		}
	}
	cout << "Game Ended: No Winners";
	cout << "\n the game will terminate in 4 seconds ";

	delay(4);
	exit(1);
	return 1;
}

int mode2() {
	cout << "\nyou are playing now as player X\n";
	system("Color 0A");
	char board[9];
	// Initiate the random number generator so that 
	// the same configuration doesn't arises
	srand(time(NULL));
	//initializing board
	for (int i = 0; i < 9; i++)
		board[i] = ' ';
	int moves[9]; // Fill the moves with numbers
	for (int i = 0; i < 9; i++)
		moves[i] = i;
	// randomise the moves
	random_shuffle(moves, moves + 9);

	cout << endl;
	Node* head = NULL;   // head of linked list 
	Node* tempPtr;

	int moveNumber = 0;
	char turn = 'X';
	int cell = 0;


	while (moveNumber < 9) {
		displayBoard(board);
		cout << "*****************************" << endl;
		cout << "Move number: " << moveNumber << endl;
		cout << "TURN: " << turn << " make your move: ";
		if (turn == HUMANMOVE) {
			cell = getint(); //this is the simple version. only input numbers here. does not check non-numeric characters..
							 //is input correct?
		}
		else if (turn == COMPUTERMOVE) {
			cell = (int)moves[moveNumber] + 1;
			while (!cellIsEmpty(cell - 1, board)) {
				if (cell < 9)
					cell = cell + 1;
				else
					cell = cell / 9;
			}
			cout << "Computer has put a " << COMPUTERMOVE << " in cell " << cell << endl;

		}
		if (rangeCorrect(cell)) { //checking if inside the range 1-9
			if (cellIsEmpty(cell - 1, board)) { //checking if cell is empty. subtracting 1, because array starts from 0.
				board[cell - 1] = turn;//storing the move in the array
				if (three(turn, board)) {//checking if there are three in a row or column or diagonal
					displayBoard(board);
					system("Color E4");
					cout << " player " << turn << " has won!!";
					cout << "\n the game will terminate in 4 seconds ";

					delay(4);
					exit(1);
					//cin >> cell; //to stop execution on windows 
					return 1;
				}

				//creating a new Node, filling its fields and adding to the list.
				tempPtr = new Node;
				// Insert at head of list 
				tempPtr->moveNumber = moveNumber; //copying moveNumber inside the node
				for (int i = 0; i < 9; i++) { //copying the elements of the board inside the board in the node
					tempPtr->board[i] = board[i];
				}
				tempPtr->nextPtr = head; //the pointer of the node points to the first element of the list
				head = tempPtr; //the head points to the new node just created
				moveNumber++; //preparing for next move.
				changeTurn(turn);//changing the turn to the next player.

			}
			else { //cell was full
				cout << "Sorry...cell " << cell << " has already been used, try again: " << endl;
			}
		}
		else {
			cout << "Sorry...cell " << cell << " is outside the range 1-9, try again: or  uccorrect input please enter valid number" << endl;
		}
	}
	cout << "Game Ended: No Winners";
	cout << "\n the game will terminate in 4 seconds ";

	delay(4);
	exit(1);
	return 1;
}

int getint()//prevents getting a char input .. and in the right range
{
	int x;
	cin >> x;
	while (cin.fail())
	{
		cout << "Error \n enter a valid number " << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> x;
	}
	return x;
}

void displayList(Node* head)
{
	Node* tempPtr = head;  // Used to traverse list without destroying head
	cout << "\n List contains: " << endl;
	while (tempPtr != NULL) {
		displayBoard(tempPtr->board);
		cout << "Move Number: " << tempPtr->moveNumber << endl << endl;
		tempPtr = tempPtr->nextPtr;
	}
	cout << "\n\n";
}
//shape of game
void displayBoard(char board[]) {
	cout << " ___   ___   ___ " << endl;
	cout << "| " << board[0] << " |" << " " << "| " << board[1] << " |" << " " << "| " << board[2] << " |" << endl;
	cout << "|___| |___| |___| " << endl;
	cout << " ___   ___   ___ " << endl;
	cout << "| " << board[3] << " |" << " " << "| " << board[4] << " |" << " " << "| " << board[5] << " |" << endl;
	cout << "|___| |___| |___| " << endl;
	cout << " ___   ___   ___ " << endl;
	cout << "| " << board[6] << " |" << " " << "| " << board[7] << " |" << " " << "| " << board[8] << " |" << endl;
	cout << "|___| |___| |___| " << endl;
	/*cout << "|"<<board[3]<<"|"<<board[4]<<"|"<<board[5]<<"|"<<endl;
	cout << "_______"<<endl;
	cout << "|"<<board[6]<<"|"<<board[7]<<"|"<<board[8]<<"|"<<endl;
	cout << "_______"<<endl;*/

}

//returns true if cell is between 1 and 9
bool rangeCorrect(int cell) {
	//checking if cell is outside the range 1 to 9.
	if (cell >= 1 && cell <= 9)
		return true;
	if (cin.fail())
		return false;
	else
		return false;
}

//returns true if the cell has already been used
bool cellIsEmpty(int cell, char  board[]) {
	if (board[cell] != ' ')
		return false;
	else
		return true;
}

void changeTurn(char& turn) {
	if (turn == 'X')
		turn = 'O';
	else
		turn = 'X';
}

bool three(char turn, char board[]) {
	if (threeInARow(turn, board) || threeInAColumn(turn, board) || threeInADiagonal(turn, board))
		return true;
	else
		return false;
}

bool threeInARow(char turn, char board[]) {
	if ((board[0] == turn && board[1] == turn && board[2] == turn) ||
		(board[3] == turn && board[4] == turn && board[5] == turn) ||
		(board[6] == turn && board[7] == turn && board[8] == turn))
		return true;
	else
		return false;
}

bool threeInAColumn(char turn, char board[]) {
	if ((board[0] == turn && board[3] == turn && board[6] == turn) ||
		(board[1] == turn && board[4] == turn && board[7] == turn) ||
		(board[2] == turn && board[5] == turn && board[8] == turn))
		return true;
	else
		return false;
}

bool threeInADiagonal(char turn, char board[]) {
	if ((board[0] == turn && board[4] == turn && board[8] == turn) ||
		(board[2] == turn && board[4] == turn && board[6] == turn))
		return true;
	else
		return false;
}

void delay(int number_of_seconds)
{
	// Converting time into milli_seconds
	int milli_seconds = 1000 * number_of_seconds;

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds)
		;
}

void choose_mood()
{
	system("Color DE");
	cout << "to play vs your friend enter 1 \nto play vs computer enter 2 \n";
	int x = 0;
	while ((x != 1) || (x != 2))
	{
		x = getint();
		if (x == 1)
			mode1();
		else if (x == 2)
			mode2();
		else

			cout << "\nenter 1 or 2 only \n ";
	}

}

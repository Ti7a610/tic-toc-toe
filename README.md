# tic-toc-toe
Game has two player, player"X" and player"O".
To any player win should complete any row or column or digonal with same symbol.
This game has two modes 
first mode play with your friend and if you want this choice enter '1'.
second mode play with computer and if you want this choice enter '2'.


the logic of code :
first function is choice mode, its function to enter user to any mode from  modes.
then function to display the shape of game is displayboard.
bord made by array of char data type, the size of array is 9 cells .
each board is node in linked list. 
then cellIsEmpty, rangeCorrect and  getint these function to make sure user doesn't enter in usable cell or number outside board or unvalid input respectivly.
changeTurn function to change turn between players X and O.
function three has three function threeInADiagonal, threeInAColumn and threeInARow to check if any player win.

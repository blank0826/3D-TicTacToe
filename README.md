# <ins>3D-TicTacToe</ins>
# Description
This is a 3D - TicTacToe played between the human user and AI. This is built based on a magic cube such that if the marking of the player gets to the sum of 42 it will be considered a strike. This has been created in **C++**.

## Brief about Magic Cube
A magic cube is the 3-dimensional equivalent of a magic square, that is, a number of integers arranged in a n × n × n pattern such that the sums of the numbers on each row, on each column, on each pillar and on each of the four main space diagonals are equal to the same number, the so-called magic constant of the cube, denoted M(n). It can be shown that if a magic cube consists of the numbers 1, 2, ..., n3, then it has magic constant

![image](https://user-images.githubusercontent.com/33955028/140877752-4b6a73ed-73de-43f4-ab65-742996ba18c2.png)

## A. Rules

### <ins>Winning Strategy:</ins>
A winning line is formed when the sum of the three numbers is 42 on the magic square, and the
three points are collinear i.e each row, column, pillar, four main space diagonals.<br />
A win is guaranteed after getting 10 collinear points.
*Hint: One of the working solutions would be to test if the three points in 3-D space have the sum
as 42 and the three points are collinear.*

## B. Objective
***(int has been defined as t.)***<br />
***(int value 3 has been defined as sz.)***

### <ins>Class MagicCube</ins>
This class ensures the creation of magic cube.

<ins>**Member Function**</ins><br/>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**1. void getMagicCube(t Cube[][sz][sz])**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Create the magic cube by doing the necessary operations.<br/>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**2. t modify(t cur)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Modify the rows and layers simultanoesly so that each row, column, pillar, four main space diagonals have a sum of 42.<br/>

### <ins>Struct Point</ins>
Keeps in the coordinates in the MagicCube.

### <ins>Functions</ins>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**1. void displayBoard(int arr[][sz][sz])**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Function to display the all 3 layers with moves of both players marked at any given call.<br/><br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**2. bool checkCollinear(Point A, Point B, Point C)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Function to check whether three given points are collinear or not using a basic mathematical formula.<br/><br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**3. t make_2(bool mm[], int C[][sz][sz])**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This function is called when the computer has to make a random move. For example the first move of the computer or when the user has just drawn one collinear line.<br/><br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**4. t possWin(vector<t> &Progress, bool nonRows[][28][28], Point M[], bool mm[])**<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This function finds whether it is possible to win for the computer or not. We know the sum of edges or diagonals must be 42 every time. So accordingly, the computer makes the move. If he has marked two points such that the difference of their sum with 42 is less than or equal to 27 there is a possibility to win for the computer. Else it also provides information if computer can make a move such that he can block a possible winning move of the human.<br/><br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**5. bool PointEarned(vector<t> &Progress, bool captured[][28][28], Point M[], bool nonRows[][28][28])**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Tells whether a human or computer has earned by a point by making a collinear line with the points they have marked using the logic of line sum must be 42.<br/><br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**6. void makeMove(vector<t> &Human, vector<t> &Comp, t C[][sz][sz], bool nonRows[][28][28], Point M[])**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This is the function takes input from human first, for the move that he wants to make and then makes a suitable move for the computer. The human move is represented as 99 and computer move is represented as 100. If computer has made less than 2 moves then it makes a random move by calling the make_2 function. Else, it uses possWin to check whether it can make a move to win or block human from winning. Again if both are not possible it makes a random move by calling make_2 function.<br/><br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**7. t main()**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;It is the main function. Initializes a class variable to make a magic cube. Then makes two 3D arrays for information. This information helps to make a move. Calls the make move function. 

# Local Setup

## Pre-Requisites
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;An IDE that supports C++.
## Installation and Execution
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1. Pull this code into any folder.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2. Open this folder in your preferred IDE.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3. Build the Project.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4. Run the [3D-TicTacToe.cpp](https://github.com/blank0826/3D-TicTacToe/blob/master/3DTicTacToe.cpp) file and TicTacToe board will be displayed.<br />

# Screenshots of the Gameplay
## Initial Board

<img src="https://user-images.githubusercontent.com/33955028/140867154-fb0951c9-8ee6-47b7-beba-7d083910f05c.png" width="350" height="290">

## First Move
After the human moves, the AI will move automatically<br /><br />
<img src="https://user-images.githubusercontent.com/33955028/140867421-b9fd3c80-c5f9-4515-bb6f-054e2342e10d.png" width="350" height="350">

## Middle of the Match

<img src="https://user-images.githubusercontent.com/33955028/140867595-a82356e5-2df4-4131-b28f-f601c3ecc0f7.png" width="350" height="350">

## Draw Condition

<img src="https://user-images.githubusercontent.com/33955028/140867790-aa9efa27-b749-4ac5-885f-da318ae86c1f.png" width="350" height="350">

# Contact
## [Aditya Srivastava](mailto:aditya26052002@gmail.com?subject=GitHub)

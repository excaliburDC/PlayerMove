#include <stdio.h>



//the initial numbers to be displayed on the game board
int grid[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
/*Score of the player
  Gets updated every time the player makes a move */
int score=0;
int i,j,xPos=0,yPos=0,player;


//prints the game board
void gameBoard()
{
    printf("\t\t _______________________ \n ");
    printf("\t\t|  %d  |  %d  |  %d  |  %d  |\n",grid[0][0],grid[0][1],grid[0][2],grid[0][3]);
    printf("\t\t|_____|_____|_____|_____|\n");
    printf("\t\t|  %d  |  %d  |  %d  |  %d  |\n",grid[1][0],grid[1][1],grid[1][2],grid[1][3]);
    printf("\t\t|_____|_____|_____|_____|\n");
    printf("\t\t|  %d  |  %d |  %d |  %d |\n",grid[2][0],grid[2][1],grid[2][2],grid[2][3]);
    printf("\t\t|_____|_____|_____|_____|\n");
    printf("\t\t|  %d |  %d |  %d |  %d |\n",grid[3][0],grid[3][1],grid[3][2],grid[3][3]);
    printf("\t\t|_____|_____|_____|_____|\n");


}


/*initializes the player at the left end corner
 and adds the score */
void playerInit()
{
    score+=grid[xPos][yPos];
    grid[xPos][yPos]=0;
    playerScore();
}


/*prints the score of the player after each move along with
the gameboard */
void playerScore()
{
   gameBoard();
   printf("\nScore: %d\n",score);

}

//function to move the player
void movePlayer(int x,int y)
{
    int tempX,tempY;

    //stores the next move in temporary variables for x & y
    tempX=xPos+x;
    tempY=yPos+y;
    /*checks if the player's move goes beyond the upper or lower bound or not
    If it doesn't then the next grid gets updated with 0 and the number in that
    grid gets added to the score of the player */
    if((tempX >= 0 && tempX <= 3) && (tempY >= 0 && tempY <= 3))
    {
        xPos=tempX;
        yPos=tempY;
        score+=grid[xPos][yPos];
        grid[xPos][yPos]=0;
        playerScore();
    }
    //else it displays a message that the player can't go beyond the boundary
    else
    {
        printf("\n\nYou can't move beyond the boundary...");
    }
}


/*function to check which button is pressed by user and then
moves the player accordingly */
void buttonSelect(char key)
{
    switch(key)
    {
        case 'w'://move up
            //xPos=xPos-1,yPos=0
            movePlayer(-1,0);
            break;

        case 's': //move down
            //xPos=xPos+1,yPos=0
            movePlayer(1,0);
            break;

        case 'a': //move left
            //xPos=xPos,yPos=yPos-1
            movePlayer(0,-1);
            break;

        case 'd': //move right
            //xPos=xPos,yPos=yPos+1
            movePlayer(0,1);
            break;

        case 'q'://exit the game
            exit(0);
            break;

        default:
            printf("\nInvalid Key...\nEnter a valid key to move...\n");
            break;

    }
}



int main()
{
    char input;

    //Starts the game by printing a message
    printf("\n\n\tStarting game...\n\tPlease wait....\n\n");
    playerScore();
    playerInit();

    //loop keeps on running until player presses 'q' to quit
    do
    {
        printf("\n\nEnter W,S,A,D to move: ");
        scanf(" %c",&input);
        buttonSelect(input);
    }
    while(input != 'q');

    printf("\n\nExiting the game....\nPlease wait...\n");

    return 0;
}

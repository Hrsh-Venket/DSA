#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <assert.h>

/*
[
0 1 2 
3 4 5
6 7 8
]
*/

// 0  denotes not filled
// 1 denotes X
// 2 denotes O

// function to check if the game has ended 

struct node {
    int weight;
    int *boardstate;
    int n;
    struct node **a;
}*root;

// checks the state of a 3 x 3 game
int game_state_checker(int *board)
{
    if ((board[0] == 1) && (board[1] == 1) && (board[2] == 1))
    {
        return 1;
    }
    if ((board[3] == 1) && (board[4] == 1) && (board[5] == 1))
    {
        return 1;
    }
    if ((board[6] == 1) && (board[7] == 1) && (board[8] == 1))
    {
        return 1;
    }
    if ((board[0] == 1) && (board[3] == 1) && (board[6] == 1))
    {
        return 1;
    }
    if ((board[1] == 1) && (board[4] == 1) && (board[7] == 1))
    {
        return 1;
    }
    if ((board[2] == 1) && (board[5] == 1) && (board[8] == 1))
    {
        return 1;
    }
    if ((board[0] == 1) && (board[4] == 1) && (board[8] == 1))
    {
        return 1;
    }
    if ((board[2] == 1) && (board[4] == 1) && (board[6] == 1))
    {
        return 1;
    }
    if ((board[0] == 2) && (board[1] == 2) && (board[2] == 2))
    {
        return 2;
    }
    if ((board[3] == 2) && (board[4] == 2) && (board[5] == 2))
    {
        return 2;
    }
    if ((board[6] == 2) && (board[7] == 2) && (board[8] == 2))
    {
        return 2;
    }
    if ((board[0] == 2) && (board[3] == 2) && (board[6] == 2))
    {
        return 2;
    }
    if ((board[1] == 2) && (board[4] == 2) && (board[7] == 2))
    {
        return 2;
    }
    if ((board[2] == 2) && (board[5] == 2) && (board[8] == 2))
    {
        return 2;
    }
    if ((board[0] == 2) && (board[4] == 2) && (board[8] == 2))
    {
        return 2;
    }
    if ((board[2] == 2) && (board[4] == 2) && (board[6] == 2))
    {
        return 2;
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
        {
            return 0;
        }
    }
    return 3;
// returns 0 if game has not ended

// returns 1 if X wins

// returns 2 if O wins

// returns 3 if tied
}

// function to print the board
void print_board(int *board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
        {
            printf(" ");
        }
        if (board[i] == 1)
        {
            printf("X");
        }
        if (board[i] == 2)
        {
            printf("O");
        }
        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
        else
        {
            printf("|");
        }
    }
}

void expand(struct node *leaf)
{

}
void simulate(struct node *leaf) // and update leaf
{
    int *board[9] = leaf->boardstate;
    int flipflop = 1; // state is oppenent move

    // rgen = rand() % 9

    while (game_state_checker(board) == 0)
    {
        // if (board[rgen] == 0) {board[rgen] = flipflop; if (flipflop == 1){flipflop = 2;} else {flipflop = 1;}}
    }
}

void backpropogate(struct node *root)
{
    
}

int main()
{
    // sets up the root for the game
    int board[9] = {0,0,0,0,0,0,0,0,0};

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root -> weight = 0; // root is unique in that its weight is the number of tests
    root -> boardstate = board;


    return 0;
}



// expand the tree till game_end_checker == true

// main function
    // notes possible options
    // randomises over those options
    // expands the tree down 
    // if win then increase path strength by 1
    // if loss then decrease path by 1
    // if tie then dont do anything




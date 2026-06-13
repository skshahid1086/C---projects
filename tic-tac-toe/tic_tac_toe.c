#include<stdio.h>
#include<stdbool.h>

void displayBoard(char board[][3]){
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

void playerInput(char board[][3],int *moves,char *currentPlayer){
    int choice;
    printf("Choose Position (1-9): ");
    scanf("%d",&choice);

    if(choice < 1 || choice > 9){
        printf("Invalid position!\n");
        return;
    }

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = *currentPlayer;
        (*moves)++;


        if (*currentPlayer == 'X') *currentPlayer = 'O';
        else *currentPlayer = 'X';
    }
    else {
        printf("Cell already taken!\n");
    }
}

int checkWinner(char board[][3]){
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

void resetBoard(char board[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

int main(){
    char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
    };

    int moves = 0;
    char currentPlayer = 'X';
    char playerWhoMoved = currentPlayer;
    bool gameOver = false;

    while (!gameOver){
        displayBoard(board);

        printf("%c's Turn\n",currentPlayer);

        playerWhoMoved = currentPlayer;

        playerInput(board,&moves,&currentPlayer);

        if(checkWinner(board)){
            displayBoard(board);
            gameOver = true;
            printf("%c won the game\n",playerWhoMoved);
            char x;
            printf("Do you want to play again? [Y/N]");
            scanf(" %c",&x);
            if(x == 'Y' || x== 'y'){
                resetBoard(board);
                gameOver = false;
                currentPlayer = 'X';
                moves = 0;
            } 
            else gameOver = true;
        }

        if(moves==9){
            printf("Game Draw\n");
            char x;
            printf("Do you want to play again? [Y/N]");
            scanf(" %c",&x);
            if(x == 'Y' || x== 'y'){
                resetBoard(board);
                gameOver = false;
                currentPlayer = 'X';
                moves = 0;
            } 
            else gameOver = true;
        }

    }

    return 0;
}
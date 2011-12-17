// Maciej Poleski
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#define init(x,y)
#define end()
#define check(x)
#else
void init(int argc,char**argv)
{
}
void end(void)
{
}
#define check(x) assert(x)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>

#define GAME 0
#define DEAD_HEAT 1
#define CIRCLE 2
#define SHARP 3

typedef struct
{
    char board[3][3];
} State;

inline int stateOfGame(State state)
{
    int i,j;
    if((state.board[0][0]==state.board[0][1] && state.board[0][1]==state.board[0][2] && state.board[0][2]=='O') ||
            (state.board[1][0]==state.board[1][1] && state.board[1][1]==state.board[1][2] && state.board[1][2]=='O') ||
            (state.board[2][0]==state.board[2][1] && state.board[2][1]==state.board[2][2] && state.board[2][2]=='O') ||
            (state.board[0][0]==state.board[1][0] && state.board[1][0]==state.board[2][0] && state.board[2][0]=='O') ||
            (state.board[0][1]==state.board[1][1] && state.board[1][1]==state.board[2][1] && state.board[2][1]=='O') ||
            (state.board[0][2]==state.board[1][2] && state.board[1][2]==state.board[2][2] && state.board[2][2]=='O') ||
            (state.board[0][0]==state.board[1][1] && state.board[1][1]==state.board[2][2] && state.board[2][2]=='O') ||
            (state.board[2][0]==state.board[1][1] && state.board[1][1]==state.board[0][2] && state.board[0][2]=='O'))
        return CIRCLE;
    else if((state.board[0][0]==state.board[0][1] && state.board[0][1]==state.board[0][2] && state.board[0][2]=='X') ||
            (state.board[1][0]==state.board[1][1] && state.board[1][1]==state.board[1][2] && state.board[1][2]=='X') ||
            (state.board[2][0]==state.board[2][1] && state.board[2][1]==state.board[2][2] && state.board[2][2]=='X') ||
            (state.board[0][0]==state.board[1][0] && state.board[1][0]==state.board[2][0] && state.board[2][0]=='X') ||
            (state.board[0][1]==state.board[1][1] && state.board[1][1]==state.board[2][1] && state.board[2][1]=='X') ||
            (state.board[0][2]==state.board[1][2] && state.board[1][2]==state.board[2][2] && state.board[2][2]=='X') ||
            (state.board[0][0]==state.board[1][1] && state.board[1][1]==state.board[2][2] && state.board[2][2]=='X') ||
            (state.board[2][0]==state.board[1][1] && state.board[1][1]==state.board[0][2] && state.board[0][2]=='X'))
        return SHARP;
    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
            if(state.board[i][j]==' ')
                return GAME;
    return DEAD_HEAT;
}

inline int whatIsTheBestGame(const State state,const int player)
{
    check(player==CIRCLE || player==SHARP);
    const int currentState=stateOfGame(state);
    if(currentState!=GAME)
        return currentState;
    const char signOfCurrentPlayer=((player==CIRCLE)?'O':'X');
    bool isDeadHeatPossible=false;
    int i,j;
    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
        {
            if(state.board[i][j]!=' ')
                continue;
            State test=state;
            test.board[i][j]=signOfCurrentPlayer;
            check(test.board[i][j]!=state.board[i][j]);
            const int r=whatIsTheBestGame(test,player^1);
            if(r==player)
                return player;
            else if(r==DEAD_HEAT)
                isDeadHeatPossible=true;
        }
    return isDeadHeatPossible?DEAD_HEAT:(player^1);
}

bool askForNewGame(void)
{
    while(true)
    {
        printf("\nCzy rozpocząć nową grę? [T/n] ");
        getchar();
        static char buffer[256];
        if(gets(buffer)==NULL)
        {
            printf("Wystąpił błąd podczas wczytywania wejścia\nKoniec gry\n");
            exit(1);
        }
        if(buffer[0]==0 || (toupper(buffer[0])=='T' && buffer[1]=='\0'))
            return true;
        else if(toupper(buffer[0])=='N' && buffer[1]=='\0')
            return false;
        printf(" >>%s<< nie jest poprawną odpowiedzią.\n",buffer);
    }
}

inline void printStateOfGame(State state)
{
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n",state.board[0][0],state.board[0][1],state.board[0][2]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n",state.board[1][0],state.board[1][1],state.board[1][2]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n",state.board[2][0],state.board[2][1],state.board[2][2]);
    printf("+---+---+---+\n");
}

inline void solution(void)
{
    do
    {
        printf("Plansza jest pusta.\n");
        State state;
        int i,j;
        for(i=0; i<3; ++i)
            for(j=0; j<3; ++j)
                state.board[i][j]=' ';
        while(true)
        {
            printf("\nTwój ruch:\n");
            int x,y;
            while(true)
            {
                printf(" > ");
                int r=scanf("%d%d",&x,&y);
                if(r==EOF)
                {
                    printf("Strumień zakończony.\nKoniec\n");
                    exit(2);
                }
                if(r!=2)
                {
                    printf("Podaj dokładnie dwie liczby - współrzędne wybranego pola.\n");
                    continue;
                }
                if(x<1 || x>3 || y<1 || y>3)
                {
                    printf("Podane współrzędne odnoszą się do miejsca poza planszą.\n");
                    continue;
                }
                --x;
                --y;
                if(state.board[x][y]!=' ')
                {
                    printf("Wybrane pole jest zajęte\n");
                    continue;
                }
                break;
            }
            state.board[x][y]='O';
            printStateOfGame(state);
            int currentStateOfGame=stateOfGame(state);
            if(currentStateOfGame==CIRCLE)
            {
                printf("Wygrywa człowiek!\n");
                check(false);
                break;
            }
            else if(currentStateOfGame==DEAD_HEAT)
            {
                printf("Remis\n");
                break;
            }
            else
            {
                check(currentStateOfGame==GAME);
                int selectedX=-1,selectedY=-1;
                int i,j;
                bool foundGame=false;
                for(i=0;i<3 && !foundGame;++i)
                    for(j=0;j<3 && !foundGame;++j)
                    {
                        if(state.board[i][j]!=' ')
                            continue;
                        State test=state;
                        test.board[i][j]='X';
                        check(state.board[i][j]!=test.board[i][j]);
                        const int r=whatIsTheBestGame(test,CIRCLE);
                        if(r==SHARP)
                        {
                            selectedX=i;
                            selectedY=j;
                            foundGame=true;
                            break;
                        }
                        else if(r==DEAD_HEAT)
                        {
                            selectedX=i;
                            selectedY=j;
                        }
                    }
                check(selectedX!=-1);
                check(selectedY!=-1);
                check(state.board[selectedX][selectedY]==' ');
                state.board[selectedX][selectedY]='X';
                printf("Ruch przeciwnika:\n > %d %d\n\nObecna plansza:\n",selectedX+1,selectedY+1);
                printStateOfGame(state);
                if(stateOfGame(state)==SHARP)
                {
                    printf("Wygrywa maszyna!\n");
                    break;
                }
            }
        }
    } while(askForNewGame());
}

#ifdef DEBUG

inline void checkAll(void)
{

}

#endif // DEBUG

int main(int argc,char**argv)
{
#ifdef DEBUG
    init(argc,argv);
    checkAll();
#endif // DEBUG
    solution();
#ifdef DEBUG
    end();
#endif // DEBUG
    return 0;
}

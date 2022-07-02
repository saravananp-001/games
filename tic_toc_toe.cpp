#include <iostream>

char val[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

char player1 = 'x';
char player2 = 'o';
char currentplayer{};

void drawBoard()
{
    for (int i = 0; i <= 2; i++)
    {
        for (int k = 0; k <= 2; k++)
        {
            std::cout << val[i][k] << " " << "|";
        }
        std::cout << "\n" << "---------\n";
    }
}

bool marker(int row_, int col_, char symbol)
{
    if (val[row_][col_] == 'x' || val[row_][col_] == 'o')
    {
        return false;
    }
    else
    {
        val[row_][col_] = symbol;
        currentplayer = (player1 == symbol) ? player2 : player1;
        system("clear");
        drawBoard();
        return true;
    }
}

bool result(bool draw = false)
{
    if (!draw)
    {
        for (int i = 0; i < 3; i++)
        {
            if ((val[i][0] == val[i][1]) && (val[i][1] == val[i][2]))
            {
                std::cout << "The WINNER is " << val[i][0] << " " << ((player1 == val[i][0]) ? "player1" : "player2") << std::endl;
                return true;
            }
            if ((val[0][i] == val[1][i]) && (val[1][i] == val[2][i]))
            {
                std::cout << "The WINNER is " << val[0][i] << " " << ((player1 == val[0][i]) ? "player1" : "player2") << std::endl;
                return true;
            }
        }
        if ((val[0][0] == val[1][1]) && (val[1][1] == val[2][2]))
        {
            std::cout << "The WINNER is " << val[0][0] << " " << ((player1 == val[0][0]) ? "player1" : "player2") << std::endl;
            return true;
        }
        if ((val[0][2] == val[1][1]) && (val[1][1] == val[2][0]))
        {
            std::cout << "The WINNER is " << val[0][2] << " " << ((player1 == val[0][2]) ? "player1" : "player2") << std::endl;
            return true;
        }
    }
    else
    {
        std::cout <<"match draw\n";
        return true;
    }
    return false;
}

void placeMarker()
{
    int place = 0;
    int row = 0, col = 0;
    for (int i = 1; i <= 9; i++)
    {
        std::cout <<"select a number : ";
        std::cin >> place;

        if (place < 1 || place > 9)
        {
            std::cout << "entered out of scop so try to give a valid number\n";
            i--;
            continue;
        }

        if (!(place > 3))
        {
            row = 0;
            col = place - 1;
            if (!marker(row, col, currentplayer))
            {
                std::cout << "entered occupied number try again\n";
                i--;
                continue;
            }
        }
        else
        {
            row = (place % 3 == 0) ? ((place / 3) - 1) : place / 3;
            col = (place % 3 == 0) ? 2 : (place % 3 - 1);
            if (!marker(row, col, currentplayer))
            {
                std::cout << "entered occupied number try again\n";
                i--;
                continue;
            }
        }

        if (i > 4)
        {
            if(result())
            {
                return;
            }
        }
    }

    result(true);
}

int main()
{
    for(;;)
    {
       drawBoard();
       
       std::cout << "Select player 1 symbol ( x (or) o ):";
       for(;;)
       {
           std::cin >> player1;
           if(player1 =='x' || player1 =='o')
           {
               break;
           }
           std::cout << "Select a vallid symbol ( x (or) o ):";
       }
         

       if (player1 == 'o')
       {
           player2 = 'x';
       }
       currentplayer = player1;

       placeMarker();
        std::cout <<"Do you want to restart the game(\"Y\")";
        char reset{};
        std::cin >> reset;
       if(!(reset == 'Y'))
       {
            break;
       }
       else
       {
            for (int i = 0,j=49; i <= 2; i++)
            {
                for (int k = 0; k <= 2; k++,j++)
                {
                    val[i][k] = (char)j;
                }
            }
            std::cout <<"\n";
       }

    }
}
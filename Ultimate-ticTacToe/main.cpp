#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


class ticTacToe
{
    
private:
    int size;
    char** board;
    bool place;
    char mark;
    
public:
    
    ticTacToe()//default cons
    {
        board = new char* [3];
        for (int i = 0; i < 3; i++)
        {
            board[i] = new char[3];
        }
        
    }
    ticTacToe(int size)//parameterized constructor//
    {
        board = new char* [size];
        for (int i = 0; i < size; i++)
        {
            board[i] = new char[size];
            
        }
    }
    
    ticTacToe(ticTacToe& obj)//copy constructor//
    {
        obj.size = size;
        obj.board = new char* [obj.size];
        for (int i = 0; i < obj.size; i++)
        {
            obj.board[i] = new char[obj.size];
        }
        for (int i = 0; i < obj.size; i++)
        {
            for (int j = 0; j < obj.size; j++)
            {
                obj.board[i][j] = board[i][j];
            }
        }
    }
    void SetBoard(int size)//intializing board with some alphabets//
    {
        char x = 'a';
        
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                board[i][j] = x; //displaying different alphabets
                x++;
            }
        }
    }
    
    void Turn(char alphabet, char Player) {
        bool wrong = true;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == alphabet)//checking if the point is available
                {
                    board[i][j] = Player; //Assigns the space with the X or O,
                    wrong = false;
                }
            }
        }
        if (wrong == true)
        {
            cout << " sorry you can only mark free spaces!!!" << endl;
        }
    }
    
    bool CheckResult(char Player, bool Over)
    {
        char* x;//row wise check
        x = new char[size];
        int count = 0;
        bool check = true;
        
        for (int i = 0; i < size; i++)
        {
            x[i] = board[i][0];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (x[i] == board[i][j] && count <= size)
                {
                    check = true;
                    count++;
                    
                }
                else
                {
                    check = false;
                    count = 0;
                    break;
                }
                if (check == true && count == size)
                {
                    Over = true;
                }
            }
        }
        char* x1;
        x1 = new char[size];
        int count1 = 0;
        bool check1 = true;
        
        for (int i = 0; i < size; i++)
        {
            x1[i] = board[0][i];
        }
        
        for (int i = 0; i < size; i++)//for column
        {
            
            for (int j = 0; j < size; j++)
            {
                if (x1[i] == board[j][i] && count1 <= size)
                {
                    check1 = true;
                    count1++;
                    
                }
                else
                {
                    check1 = false;
                    count1 = 0;
                    break;
                    
                }
                if (check1 == true && count1 == size)
                {
                    Over = true;
                }
            }
        }
        delete x;
        delete x1;
        x = nullptr;
        x1 = nullptr;
        //Checking the Diagonals
        char y = board[0][0];
        char z = board[0][size - 1];
        bool found = true;
        bool found1 = true;
        int counter = 0;
        int counter1 = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j) {
                    if (board[i][j] == y)
                    {
                        found = true;
                        counter++;
                    }
                    else
                    {
                        found = false;
                        counter = 0;
                        
                    }
                    if (counter == size && found == true)
                    {
                        Over = true;
                    }
                }
                
            }
            
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i + j == size - 1)
                {
                    if (board[i][j] == z)
                    {
                        found1 = true;
                        counter1++;
                    }
                    else
                    {
                        found1 = false;
                        counter1 = 0;
                        
                        
                    }
                    
                }
                if (counter1 == size && found1 == true)
                {
                    Over = true;
                    
                }
            }
        }
        
        result_print(Over, Player);
        return Over;
    }
    
    void result_print(bool GameOver, char Player)
    {
        if (GameOver == true)
        {
            cout << endl << endl << " CONGRATULATIONS --Player " << Player << " won!!!!" << endl << endl;
            
        }
    }
    
    bool CheckDraw(bool GameOver)
    {
        char n = 'a';
        
        int counter = 0;
        
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == n)//checking if the places are taken or not
                {
                    counter++;
                }
                n++;
            }
        }
        if (counter < 1)
        {
            cout << "Game is draw!!";
            GameOver = true;
        }
        return GameOver;
    }
    void PrintBoard(int size)
    {
        this->size = size;
        
        
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << board[i][j] << "  ";
            }cout << endl;
        }
        
    }
    
    void save(int size)
    {
        ofstream save;
        save.open("UltimateGame.txt");
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                save << board[i][j] << " ";
            }
            save << endl;
        }
    }
    void load(int size) {
        ifstream save;
        save.open("UltimateGame.txt");
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                save >> board[i][j];
            }
            
        }
    }
    
    friend ostream& operator << (ostream& out, const ticTacToe& obj);
    
    
    
    
    void set_place(int x,char m)
    {
        place = x;
        mark = m;
        
    }
    void ios(int i,int j,char mark)
    {
        board[i][j] = mark;
    }
    
    bool final_checker(char Player, bool &GameOver)
    {
        
        for (int i = 0; i < 3; i++) //Increment i to check rows
        {
            if (board[i][0] == board[i][1] && board[i][1] ==
                board[i][2])
                GameOver = true;
        }
        for (int i = 0; i < 3; i++) //Increment i to check column
        {
            if (board[0][i] == board[1][i] && board[1][i] ==
                board[2][i]) GameOver = true;
        }
        //Checking the Diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            GameOver = true;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            GameOver = true;
        }
        if (GameOver == true)
        {
            cout << endl << endl << "------||| CONGRATULATIONS --Player " << Player << " won the ultimate tictactoe!!!!!!!!!" << endl << endl;
            
        }
        return GameOver;
    }
    
    
    
    
    ~ticTacToe()
    {
        for (int i = 0; i < size; i++) {
            
            delete[] board[i]; // delete sub array
        }
        delete[] board; //delete outer array
        board = NULL;
    };
    
};

ostream& operator << (ostream& out, const ticTacToe& obj) {
    
    for (int i = 0; i < obj.size; i++) {
        for (int j = 0; j < obj.size; j++) {
            out << obj.board[i][j] << " ";
            
        }
        out << endl;
    }
    return out;
}
void working(int size, ticTacToe& myGame, char &Player, bool &gamecycle, char alphabet, bool game,int place)
{
    myGame.PrintBoard(size);
    cout << endl << "Player " << Player << " "" << ""it's your turn: " << endl;
    cin >> alphabet;
    
    
    myGame.Turn(alphabet, Player);
    bool game2;
    game = myGame.CheckResult(Player, game);
    game2 = myGame.CheckDraw(game);
    system("CLS");
    if (game2 == true)
    {
        myGame.PrintBoard(size);
        system("pause");
        gamecycle = true;
        myGame.set_place(place, Player);
        if (Player == 'X')//for alaternate selection of marks
        {
            Player = 'O';
        }
        else
        {
            Player = 'X';
        }
        
    }
    if (Player == 'X')//for alaternate selection of marks
    {
        Player = 'O';
    }
    else
    {
        Player = 'X';
    }
    
    
    
    
    
    
}



int main()
{
    bool gamecycle = false;
    bool game = false;
    char Player = 'X';
    char alphabet='a';
    int x, y;
    cout << "-----------W-E-L-L-C-O-M-E------T-O------T-I-C-T-A-C-T-O-E------------" << endl << endl;;
    cout << "Read the instructions please: " << endl;
    cout << "press those keywords which you want to select from game to mark your move:" << endl;
    cout << "For example " << endl << endl;
    cout << "Table will be shown like this:" << endl;
    cout << " a  b  c" << endl;
    cout << " d  e  f " << endl;
    cout << " f  g  h " << endl;
    cout << "so to select press a,b,c" << endl;
    cout << "-------------" << endl;
    cout << "Enter the size" << endl;
    cin >> x;
    cout << "Press 1 To play a loaded game?" << endl;
    cout << "press 2 to play normally" << endl;
    cin >> y;
    if (y == 2) {
        ticTacToe myGame[3][3];
        
        ticTacToe myGame2(3);
        myGame2.SetBoard(3);
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                myGame[i][j].SetBoard(x);//setting up all 3 by 3
        cout << endl;
        
        cout << "First person will choose X or O" << endl;
        cin >> Player;
        bool enter1=true;
        bool enter2 = true;
        bool enter3 = true;
        bool enter4 = true;
        bool enter5 = true;
        bool enter6 = true;
        bool enter7 = true;
        bool enter8 = true;
        bool enter9 = true;
        
        bool gamecycle1 = false;
        int c = 0;
        int place;
        while (gamecycle1 == false)
        {
            gamecycle = false;
            cout << "Enter the coordinate of the part of box you want to play first" << endl;
            cout << " 1  2  3" << endl;
            cout << " 4  5  6" << endl;
            cout << " 7  8  9" << endl;
            
            cin >> place;
            
            if (place == 1 && enter1 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[0][0], Player, gamecycle, alphabet, game, place);
                
                myGame2.ios(0, 0, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter1 = false;
            }
            
            if (place == 2 && enter2 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[0][1], Player, gamecycle, alphabet, game, place);
                
                myGame2.ios(0, 1, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter2 = false;
            }
            if (place == 3 && enter3 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[0][2], Player, gamecycle, alphabet, game, place);
                
                myGame2.ios(0, 2, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter3 = false;
            }
            if (place == 4 && enter4 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[1][0], Player, gamecycle, alphabet, game, place);
                
                myGame2.ios(1, 0, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter4 = false;
            }
            if (place == 5 && enter5 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[1][1], Player, gamecycle, alphabet, game, place);
                myGame2.ios(1, 1, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter5 = false;
            }
            if (place == 6 && enter6 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[1][2], Player, gamecycle, alphabet, game, place);
                myGame2.ios(1, 2, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter6 = false;
            }
            if (place == 7 && enter7 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[2][0], Player, gamecycle, alphabet, game, place);
                myGame2.ios(2, 0, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter7 = false;
                
            }
            if (place == 8 && enter8 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[2][1], Player, gamecycle, alphabet, game, place);
                myGame2.ios(2, 1, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter8 = false;
                
            }if (place == 9 && enter9 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[2][2], Player, gamecycle, alphabet, game, place);
                myGame2.ios(2, 2, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter9 = false;
                
            }
            
            
            myGame2.save(3);
            myGame2.final_checker(Player, gamecycle1);
            c++;
            if(c==9 && gamecycle1==false)
            {
                cout << "ultimate game is draw!!!" << endl;
                gamecycle1 = true;
                
            }
            
            
            
        }
        
        
        
        
        
        
        system("pause");
    }
    if (y == 1)
    {
        
        
        ticTacToe myGame[3][3];
        
        ticTacToe myGame2(3);
        myGame2.SetBoard(3);
        myGame2.load(3);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                myGame[i][j].SetBoard(x);//setting up all 3 by 3
        cout << endl;
        
        cout << "First person will choose X or O" << endl;
        cin >> Player;
        bool enter1 = true;
        bool enter2 = true;
        bool enter3 = true;
        bool enter4 = true;
        bool enter5 = true;
        bool enter6 = true;
        bool enter7 = true;
        bool enter8 = true;
        bool enter9 = true;
        
        bool gamecycle1 = false;
        int c = 0;
        int place;
        while (gamecycle1 == false)
        {
            gamecycle = false;
            cout << "Enter the coordinate of the part of box you want to play first" << endl;
            cout << " 1  2  3" << endl;
            cout << " 4  5  6" << endl;
            cout << " 7  8  9" << endl;
            
            
            cin >> place;
            
            if (place == 1 && enter1 == true)
            {
                while (gamecycle == false)
                    
                    working(x, myGame[0][0], Player, gamecycle, alphabet, game, place);
                
                myGame2.ios(0, 0, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter1 = false;
            }
            
            if (place == 2 && enter2 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[0][1], Player, gamecycle, alphabet, game, place);
                
                myGame2.ios(0, 1, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter2 = false;
            }
            if (place == 3 && enter3 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[0][2], Player, gamecycle, alphabet, game, place);
                
                myGame2.ios(0, 2, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter3 = false;
            }
            if (place == 4 && enter4 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[1][0], Player, gamecycle, alphabet, game, place);
                
                myGame2.ios(1, 0, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter4 = false;
            }
            if (place == 5 && enter5 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[1][1], Player, gamecycle, alphabet, game, place);
                myGame2.ios(1, 1, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter5 = false;
            }
            if (place == 6 && enter6 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[1][2], Player, gamecycle, alphabet, game, place);
                myGame2.ios(1, 2, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter6 = false;
            }
            if (place == 7 && enter7 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[2][0], Player, gamecycle, alphabet, game, place);
                myGame2.ios(2, 0, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter7 = false;
                
            }
            if (place == 8 && enter8 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[2][1], Player, gamecycle, alphabet, game, place);
                myGame2.ios(2, 1, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter8 = false;
                
            }if (place == 9 && enter9 == true)
            {
                while (gamecycle == false)
                    working(x, myGame[2][2], Player, gamecycle, alphabet, game, place);
                myGame2.ios(2, 2, Player);
                cout << "total score:" << endl;
                myGame2.PrintBoard(3);
                enter9 = false;
                
            }
            
            myGame2.save(3);
            myGame2.final_checker(Player, gamecycle1);
            c++;
            if (c == 9 && gamecycle1 == false)
            {
                cout << "ultimate game is draw!!!" << endl;
                gamecycle1 = true;
                
            }
            
            
            
        }
        
        
        
        
        
        
        system("pause");
        
    }
    return 0;
}

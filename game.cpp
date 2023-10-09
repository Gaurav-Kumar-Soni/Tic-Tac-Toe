#include <bits/stdc++.h>
using namespace std;

bool validInput(int x, int y, char arr[3][3]){
    if ((x > 0 && x < 4) && (y > 0 && y < 4) && arr[x - 1][y - 1] == ' '){
        return true;
    }
    return false;
}

void printBoard(char arr[3][3]){
    for (int i = 0; i < 3; i++){
        cout << '|';
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << '|';
        }
        cout << endl;
    }
}
bool check_win(char arr[3][3]){
    for (int i = 0; i < 3; i++){
        if ((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] != ' ') ||
            (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) && arr[2][i] != ' ')
            return true;
    }

    if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] != ' ') ||
        (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] != ' '))
        return true;

    return false;
}
int main()
{ 
    cout<<"Input Co-ordinates with a space and with in range of [1,1] to [3,3]."<<endl<<endl;
    char arr[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int count = 0;
    int p;
    int x, y;
    int flag = 0;
    while (!check_win(arr)){
        if (count % 2 == 0){
            p = 1;
        }
        else
            p = 2;
        if (count >= 9){
            flag = 0;
            break;
        }
        cout << "chance of player " << p << " : ";
        cin >> x >> y;
        if (!validInput(x, y, arr)){
            cout << "Invalid input!" << endl;
            continue;
        }
        if (p == 1){
            arr[x - 1][y - 1] = 'X';
        }
        else
            arr[x - 1][y - 1] = 'O';
        count++;
        printBoard(arr);
        flag = 1;
    }
    if (flag)
        cout << "player " << p << " win" << endl;
    else
        cout << "Draw!" << endl;
    return 0;
}

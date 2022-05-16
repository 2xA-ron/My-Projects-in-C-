/*
    Program Description: This program is a single player game where at the start 25 lights are turned on.
	Cells in the grid are labeled -Off means '-' and on means '*'
	Your goal is to turn off all 25 lights thats when the game ends.
*/

#include <iostream>
using namespace std;

class LightsOff{   // Class Declaration;

private:

    char gameboard[5][5]; // Light Grid 5x5
    int o,f;

    // game state
    int numLightsOn;
    int numLightsOff;
    bool gameOver;

    void updateGameState(){    // private utility / prototype
    numLightsOn = 0;
    numLightsOff = 0;
    for(o =0; o < 5; o++){
        for(f = 0; f < 5; f++){
            if(gameboard[o][f] =='*'){  // evaluating the conditions with if statement
                numLightsOn++;
            } else {
            numLightsOff++;
            }
        }
    }
    (numLightsOff==25)? gameOver = true : gameOver = false; // if game=25 game over if not game is false and continues
}
public:
    // Default constructor-initializing gameboard state
    LightsOff(){
        for(o =0; o < 5; o++){
            for(f = 0; f < 5; f++){   // Nested loop
            gameboard[o][f]='*';
        }
    }
    numLightsOn = 25;  // set to 25
    numLightsOff = o;  // set to 0
    gameOver = false;  // set to false
    }
    int getLightsOn(){
        return numLightsOn;
    }
    int getLightsOff(){
        return numLightsOff;
    }
    bool getGameOver(){
        return gameOver;
    }
    void displayLights(){
      for(o =0; o < 5; o++){
            for(f = 0; f < 5; f++){
                    cout << gameboard[o][f]<<" ";
            }
            cout << endl;
      }
    }
void switchLights (int r, int c){              // // (above, below, right, left)
    int ax[] = {-1, 0, 1, 0};
    int ay[] = {0, -1, 0, 1};
    (gameboard[r][c]=='*')? gameboard[r][c] = '-':gameboard[r][c] = '*';

    for(int s = 0; s < 4;s++){                 // evaluating all the sides
        int row = ax[s] + r;
        int col = ay[s] + c;

        // Updating only if not out of bounds
        if (row >= 0 && row <=4 && col >= 0 && col <= 4){
                // Lights on or off determination
            (gameboard[row][col] == '*')? gameboard[row][col] = '-' : gameboard[row][col] = '*';
        }
    }
    // Game state update
    updateGameState();

    }
};
int main(){
    bool endGame = false;
    int row;
    int column;

    LightsOff grid;
    cout << "Welcome to the Lights Off Game!! " << endl;

    // Display board game state
    grid.displayLights();
    cout << " On:" << grid.getLightsOn() << " off:" << grid.getLightsOff() << " gameOver: ";
    grid.getGameOver()== false? cout << " false\n" : cout << " true\n";

    // Game Loop
    while (!endGame){
// set the lights and game state
        cout << " Enter a row and a column [0-4]: \n";
        cin >> row;
        cin >> column;

        if (row >= 5 || row <=-1 || column >=5 || column <= -1){
            cout << " Range out of bounds enter between [0-4]\n";
            continue;
        }
        grid.switchLights(row, column);
        // Display lights
        grid.displayLights();
        cout << "On: " << grid.getLightsOn() << " off:" << grid.getLightsOff() << " gameOver:";
        // Game is over when true
        endGame = grid.getGameOver();
    }
    cout << "End Game" << endl;
    return 0;
}

/*
Welcome to the Lights Off Game!!
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
 On:25 off:5 gameOver:  false
 Enter a row and a column [0-4]:
2
2
* * * * *
* * - * *
* - - - *
* * - * *
* * * * *
On: 20 off:5 gameOver: Enter a row and a column [0-4]:
1
0
- * * * *
- - - * *
- - - - *
* * - * *
* * * * *
On: 16 off:9 gameOver: Enter a row and a column [0-4]:
1
1
- - * * *
* * * * *
- * - - *
* * - * *
* * * * *
On: 19 off:6 gameOver: Enter a row and a column [0-4]:
1
2
- - - * *
* - - - *
- * * - *
* * - * *
* * * * *
On: 16 off:9 gameOver: Enter a row and a column [0-4]:
3
4
- - - * *
* - - - *
- * * - -
* * - - -
* * * * -
On: 12 off:13 gameOver: Enter a row and a column [0-4]:
2
3
- - - * *
* - - * *
- * - * *
* * - * -
* * * * -
On: 15 off:10 gameOver: Enter a row and a column [0-4]:
4
2
- - - * *
* - - * *
- * - * *
* * * * -
* - - - -
On: 13 off:12 gameOver: Enter a row and a column [0-4]:





*/






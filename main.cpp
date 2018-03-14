#include <iostream>
using namespace std;

class crossword {

private:
int length;
  int x = 0;
  int y = 0;
  int x_i = 0;
  int y_i = 0;
  char input[3]; //bc only 3 letter words exist
public:
void program();
};

void crossword::program(){
//char 2D array
  char puzzle[4][4] = {{'f', 'k', 's', 'a'},
                       {'l', 'u', 'o', 'w'},
                       {'y', 'o', 'n', 'a'},
                       {'x', 't', 'o', 'y'}
  };
//prompt user for word to search
  cout << "\n\t   |f  k  s  a|""""\n\t   |l  u  o  w|""\n\t   |y  o  n  a|""\n\t   |x  t  o  y|""\n\n Enter the word you want to search:" <<endl;
  cin >> input;



//traversing through the board
  for (int i = 0;i < 4; i++){
    for (int j = 0; j<4; j++){
      if (puzzle[i][j] == input[0]){//when position of array = to user input then set position to var
        x_i = i;
        y_i = j;
        break;
      }

      else {
        continue;
      }

    }

  }
//figuring the possible directions in which you can look things up
  char dir[10];
  int count = 0;
  if (y_i - (2) >= 0){
    dir[count] = 'Q';
    count ++;
    if (y_i + (2) <= 4){
      dir[count] = 'W';
      count++;
    }

    else if (y_i - (2) >= 0){
      dir[count] = 'E';
      count++;
    }
  }

  else if(y_i + (2) <= 4){
    dir[count] = 'R';
    count ++;

    if (y_i + (2) <= 4){
      dir[count] = 'B';
      count++;
    }

    else if (y_i - (2) >= 0){
      dir[count] = 'A';
      count++;
    }
  }

  if (x_i - (2) >= 0){
    dir[count] = 'U';
    count ++;

  }

  else if(x_i + (2) <= 4){
    dir[count] = 'D';
    count ++;

  }
 
//after you the direction is determined, it's placed into this switch case
  int flag = 0;
  for (int i = 0; i<10; i++){ 
    if (flag == 0) {
// each case compares the position & dir to user input
      switch (dir[i]) {
        case 'Q' : if (puzzle[x_i][y_i-1] == input[1] && puzzle[x_i][y_i-2] == input[2]){
                    flag = 1;
                    cout << "Word Found!" << endl; //word is found if everything matches up
        }
        break;
        case 'R' : if (puzzle[x_i][y_i+1] == input[1] && puzzle[x_i][y_i+2] == input[2]){
                    flag = 1;
                    cout << "Word Found!" << endl;
        }
        break;

        case 'U' :if (puzzle[x_i-1][y_i] == input[1] && puzzle[x_i-2][y_i] == input[2]){
                    flag = 1;
                    cout << "Word Found!" << endl;
        }
        break;

        case 'D' :if (puzzle[x_i+1][y_i] == input[1] && puzzle[x_i+2][y_i] == input[2]){
                    flag = 1;
                    cout << "Word Found!" << endl;
        }
        break;

        case 'A' :if (puzzle[x_i-1][y_i+1] == input[1] && puzzle[x_i-2][y_i+2] == input[2]){
                    flag = 1;
                    cout << "Word Found!" << endl;
        }
        break;

        case 'B' :if (puzzle[x_i+1][y_i+1] == input[1] && puzzle[x_i+2][y_i+2] == input[2]){
                  flag = 1;
                  cout << "Word Found!" << endl;
        }
        break;

        case 'W' :if (puzzle[x_i+1][y_i-1] == input[1] && puzzle[x_i+2][y_i-2] == input[2]){
                  flag = 1;
                  cout << "Word Found!" << endl;
        }
        break;

        case 'E' :if (puzzle[x_i-1][y_i-1] == input[1] && puzzle[x_i-2][y_i-2] == input[2]){
                  flag = 1;
                  cout << "Word Found!" << endl;
        }
        break;

        default :flag = 0;//means word was not found, if it was: flag =1
                 break;
      }
    }

    else {
       break;
    }

  }

  if (flag == 0){
    cout << "Word not found!" << endl;
  }
}

int main() {
  crossword obj;//creating an object
  obj.program();//running the program

return 0;

};
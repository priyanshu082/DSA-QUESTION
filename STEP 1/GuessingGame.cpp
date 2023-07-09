#include <iostream>
#include <cmath> //this is added to do maths function

using namespace std;
int main()
{
    int number;
    int guessNo = 1;
    int guessedNo;
    int guessLimit = 5;
    bool outOfGuess = false;

    cout <<"Player 1 please Enter the number You want keep secret and play game with Player 2"<<endl;
    cin >> number;
    cout<< "Great!!, Now Player 2 can guess the secret Number . Remember you have only 5 guesses." << endl;

    while (number != guessedNo)
    {
        if (guessNo <= guessLimit)
        {
            cout << "Guess" << guessNo ;
            cin >> guessedNo;
            if (number!= guessedNo)
            {
             cout<< "Wrong, try again."<<endl;
            }else {
               cout<< "Congrats You guessed it right!!" <<endl;
            }
            
           
            guessNo++;
        }
        else
        {
            outOfGuess = true;
        }
    }

    if (outOfGuess)
    {
        cout << "You Loose!!!" << endl;
    }
    else
    {
        cout << "You Win!!!" << endl;
    }
    return 0;
}
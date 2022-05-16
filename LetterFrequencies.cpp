/*
    Program Description:
    This program demonstrates the use of the get member
    functions of the istream class and evaluates
    the text in a file that is opened by the program. An error is
    flagged if the program can not be open otherwise the program counts the
    letter frequency of a letter and stores the count of that specific letter within
    an array. After all
    letters have been evaluated for a letter frequency and tallied up from the (input.txt)
    file from letters a-z the program then
    displays count total of each letter that is referenced from the file.

*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//  starts before so that the letters increment using StartChar
char StartChar = 'A' - 1;
struct Letter
{
    int count = 0;               // Count intitalized
    char letter = ++StartChar;   // Count number of chararters
};


int main()
{
    // Variables needed to read file one character at a time
    string fileName;
    fstream file;
    char ch;     // character read from the file

    // Get file name and open file
    cout << "Enter a file name: ";
    cin >> fileName;

    file.open(fileName.c_str(), ios::in);
    if (!file)
    {
        cout << fileName << " could not be opened.\n";
        return 1;
    }


    Letter letter_freq [26]{}; // Number of letters in Alphabet


    // Read file one character at a time and echo to screen
    ch = file.get();
    while (ch != EOF)
    {
        cout << ch;
        ch = toupper(file.get());

        int array = ch - 'A';
         // instance referencing a letter stored in the array
        Letter& instance = letter_freq[array];
        instance.count = instance.count + 1; // Counting intsances of letter(s) from array

    }

    for (size_t i = 0; i < 26; i++)
    {
         Letter& instance = letter_freq[i];

         if (instance.count > 0){
             cout << instance.letter << ": " << instance.count << endl;
         }
    }



    // Close file
    file.close();
    return 0;
}

/*
	Output:

	Enter a file name: input.txt
MY FATHER'S FAMILY NAME BEING PIRRIP, AND MY CHRISTIAN NAME PHILLIP, MY
INFANT TONGUE  COULD MAKE OF BOTH NAMES NOTHING LONGER OR MORE EXPLICIT
THAN PIP. SO, I CALLED  MYSELF PIP, AND CAME TO BE CALLED PIP.

CHARLES DICKENS, OPENING OF GREAT EXPECTATIONS.
A: 17
B: 3
C: 9
D: 6
E: 21
F: 6
G: 6
H: 7
I: 19
K: 2
L: 12
M: 10
N: 18
O: 13
P: 13
R: 9
S: 8
T: 12
U: 2
X: 2
Y: 5

*/


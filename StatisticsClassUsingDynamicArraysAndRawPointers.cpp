//  Statistics class
//  - using a dynamic array
//  This class uses the class STATISTICS to gather statistical data on an array of randomly
//  generated numbers of a user-specified length. The values range from 0 - user specified maximum value.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

// class declaration
class Statistics
{
  private:
    int length;
    int *numbers;

    void bubbleSort(int *) const;   // private utility

  public:
    Statistics();
    Statistics(int, int);
    ~Statistics();

    double getAverage() const;
    double getMedian() const;
    void displayNumbers() const;
};

Statistics::Statistics()   // Default Constructor
{
    length = 0;
    numbers = nullptr;
}

Statistics::Statistics(int _length, int max)   // Overloaded Constructor
{
    if (_length > 0)
    {
        unsigned int seed;
        seed = time(0);
        srand(seed);
        length = _length;
        numbers = new int[length];

        for (int i = 0; i < length; i++)
        {
            numbers[i] = (rand() % max) + 1 ;  //array with random numbers in the range 0 to max
        }

    }else{
        length = 0;
        numbers = nullptr;
    }
}
Statistics::~Statistics()   // Deallocates the dynamic array
{
    delete [] numbers;
    numbers = nullptr;
}


// class member function definitions
void Statistics::displayNumbers()const
{
    int colCount = 0;
    for (int i =0; i < length; i++)
    {
        string number = to_string(numbers[i]);   // displays the numbers in the array
        colCount += 1;

        cout << numbers[i] << ", ";
        if (colCount == 80)
            cout <<endl;
    }

}

double Statistics::getAverage() const  // Finding the Average
{
    double average = 0;

    for (int i =0; i < length; i++)
    {
        average += numbers[i];
    }
    return average / length;
}

double Statistics::getMedian() const   // Finding the Median
{
    int *tempArray = new int[length];   // Initiating the Temporary Array
    double median =0;

    for (int i = 0; i < length; i++)
    {
        tempArray[i] = numbers[i];
    }


    bubbleSort(tempArray);  // Temporary array Dynamic array
                            // to sort the values to preserve the original ordering of numbers
    if (length % 2 !=0)
    {
        median = tempArray[length/2];

    }
    else
    {
        median = (double)(tempArray[(length-1)/2]+tempArray[length/2])/2.0; //
    }
                        // tempArray exists only for the duration of the function call and doesn't require deallocation

    return median;
}

// main
int main()
{
    int num = 0, max = 0;

    srand(time(0));		// seed the random number generator

    cout << "Enter number of values: ";
    cin >> num;
    cout << "Enter max value: ";
    cin >> max;

    Statistics arrayNum(num, max);

    arrayNum.displayNumbers();
    cout << endl;

    cout << "The average is " << arrayNum.getAverage() << endl;
    cout << "The median is " << arrayNum.getMedian() << endl;

    return 0;
}

// bubbleSort
//  a private utility for sorting a temporary array
//  does not allow sorting of the actual numbers array class member
void Statistics::bubbleSort(int *array) const
{
	int temp;
	bool swap;

    // do not allow self sort
    if (array == numbers)
        return;

	do
	{
		swap = false;
		for (int count = 0; count < length - 1; count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

/*
 Program Output:

 Enter number of values: 100
Enter max value: 99
29, 19, 75, 23, 3, 23, 56, 97, 30, 76, 23, 39, 26, 21, 28, 9, 84, 78, 51, 69, 70, 52, 44, 27, 22, 1, 45, 89, 15, 54, 64, 78, 64, 72, 37, 73, 34, 25, 47, 22, 32, 68, 1, 5, 58, 19, 71, 95, 78, 97, 87, 75, 88, 29, 85, 69, 64, 86, 96, 64, 32, 59, 97, 63, 72, 36, 83, 25, 88, 77, 5, 75, 53, 75, 11, 29, 64, 65, 58, 77,
16, 1, 25, 27, 31, 46, 65, 11, 51, 1, 82, 77, 21, 9, 29, 65, 91, 69, 10, 73,
The average is 50.05
The median is 53.5



Enter number of values: 9
Enter max value: 99
90, 27, 89, 71, 38, 82, 12, 9, 94,
The average is 56.8889
The median is 71



*/

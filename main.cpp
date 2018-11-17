#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


double *allocateArray(std::string fileName, int &arraySize, int &counter)
{
 	double input= 0;
	std::ifstream myReadFile;
    
    myReadFile.open(fileName);
	double *arr = new double[arraySize]{0.0};
    
    while (myReadFile >> input)
    {
		input= round( input* 1000.0 ) / 1000.0;

		counter++;
		if(counter == arraySize)
		{
			arr[arraySize -1] = input;
			
		}

		else
		{
			double *tempArray = new double[arraySize +1]{0.0};
			for(int i = 0; i < arraySize; i++)
			{
				tempArray[i] = arr[i];
			}
			delete[] arr;
			arraySize++;
			arr = new double[arraySize];
			for(int x = 0; x < arraySize; x++)
			{
				arr[x] = tempArray[x]; 
			}
			arr[arraySize-1] = input;
		}

    }
    myReadFile.close();
	if(!myReadFile.eof())
		{
			exit(EXIT_FAILURE);
			
		}
	
	return arr;
}

void output(double *arr, int arraySize,int counter)
{
	double sum = 0.0;

	for(int x = 0; x < arraySize; x++)
	{
		sum += arr[x];
	}
	double average = sum/counter;
	std::cout << "Output:  ";

	for(int i = 0; i < arraySize; i++)
	{
		if(arr[i] > average)
		{
			std::cout << arr[i] << "  ";
		}
	}
}
int main()
{
    
   	int arraySize = 1;
	int counter = 0;

	

    double *arr = allocateArray("input.in", arraySize, counter);
    
	std::cout << "Input:  ";
    for(int x = 0; x < arraySize; x++)
	{
		
		std::cout << arr[x] << "  ";
	}
	output(arr, arraySize, counter);

	
    
    
    getchar();
    return 0;
}


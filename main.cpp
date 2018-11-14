#include <iostream>
#include <fstream>
#include <string>


int *allocateArray(std::string fileName, int &arraySize, int &counter)
{
 	int a = 0;
	std::ifstream myReadFile;
    
    myReadFile.open(fileName);
	int *arr = new int[arraySize]{0};
    
    while (myReadFile >> a)
    {
		counter++;
		if(counter == arraySize)
		{
			arr[arraySize -1] = a;
			
		}

		else
		{
			int *tempArray = new int[arraySize +1]{0};
			for(int i = 0; i < arraySize; i++)
			{
				tempArray[i] = arr[i];
			}
			delete[] arr;
			arraySize++;
			arr = new int[arraySize];
			for(int x = 0; x < arraySize; x++)
			{
				arr[x] = tempArray[x]; 
			}
			arr[arraySize-1] = a;
		}

    }
    myReadFile.close();
	
	return arr;
}

void output(int *arr, int arraySize,int counter)
{
	int sum = 0;

	for(int x = 0; x < arraySize; x++)
	{
		sum += arr[x];
	}
	int average = sum/counter;
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

	

    int *arr = allocateArray("input.in", arraySize, counter);
    
	std::cout << "Input:  ";
    for(int x = 0; x < arraySize; x++)
	{
		std::cout << arr[x] << "  ";
	}
	output(arr, arraySize, counter);

	
    
    
    getchar();
    return 0;
}


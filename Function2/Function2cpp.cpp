#include <iostream> 
#include <windows.h>
using namespace std;


void Rectangle(int width, int height, char a, char b, int frameColor, int fillColor)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
			{
				SetConsoleTextAttribute(h, frameColor);
				cout << (char)a;
			}
			else {
				SetConsoleTextAttribute(h, fillColor);
					cout << (char)b;
			}
		}
		cout << "\n";
	}
}

int IsNumberPrime(int number)
{
	int divider = 2;
	for (divider = 2; divider < number; divider++)
	{
		if (number % divider == 0)
		{
			cout << "number is not prime" << "\n";
			return 0;
		}
	}
	cout << "number is prime" << "\n";
}

void Sum(int a, int b)
{
	int sum = 0;
	for (int i = a; i <= b; i++)	
		sum += i;
	cout << sum << "\n";
}

void DisplayMinMaxArray(int arr[], int size)
{
	int max = arr[0];
	int min = arr[0];
	int indexMin = 0;
	int indexMax = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] <= min)
		{
			min = arr[i];
			indexMin = i;
		}
		if (arr[i] >= max)
		{
			max = arr[i];
			indexMax = i;
		}
	}
	cout << "Maximum number is " << max << " index of maximum number is " << indexMax << "\n";
	cout << "Minimum number is " << min << " index of minimum number is " << indexMin << "\n";
}

void OppositeArray(int arr[], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		arr[i] += arr[size - i - 1];
		arr[size - i - 1] = arr[i] - arr[size - i - 1];
		arr[i] = arr[i] - arr[size - i - 1];
	}
	for (int i = 0; i < size; i++)
		cout << arr[i] << "  ";
	cout << "\n";
}



int main()
{
	Rectangle(10, 5, '@', '#', 12, 14);
	IsNumberPrime(13);
	Sum(10, 20);
	int arr[10] = { 10, 15, 0, 42, 487, -15, 63, -123, 11, 52 };
	DisplayMinMaxArray(arr, 10);
	OppositeArray(arr, 10);
}
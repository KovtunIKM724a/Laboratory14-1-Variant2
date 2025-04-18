#include <iostream>
using namespace std;

const int NOTEXISTERROR = -1;

int BinarySearch(int* a, const int size, int searchElement)
{
	int low = 0;
	int high = size - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (a[mid] < searchElement)
		{
			low = mid + 1;
		}
		else if (a[mid] > searchElement)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}

         return NOTEXISTERROR;
}


int main() {
    int number;
    int a;
    int index;

    cout << "Enter a six-digit number: ";
    cin >> number;

    int divisors[100];
    int count = 0;

    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            divisors[count] = i;
            count++;
        }
    }

    cout << "Divisors of a number " << number << ": ";
    for (int i = 0; i < count; i++) {
        cout << divisors[i] << " ";
    }
    cout << endl;

    cout << "What number would you like to find?: ";
    cin >> a;
    index = BinarySearch(divisors, count, a);
	
    if (index == NOTEXISTERROR)
    {
	cout << "An element " << a << " was not found";
    }
    else
    {
    cout << "An element " << a << " has index " << index;
    }
}

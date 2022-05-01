/*
Use a one-dimensional array to solve the following problem.
• To initialize an array of 20 numbers. Program will take input from user and
store it into the array if & only if the input is validated.
• An input validate true if & only if the number is between 10-100 & if the
number is not duplicate to any previous number and false otherwise.
• Then perform Ascending Sort an array and display the result.
*/

#include <iostream>
using namespace std;

void printArray(int[], int);
bool searchArray(int[], int, int);
void applySort(int[], int);

int main() {
    int arr[20];

    arr[0] = -1;
    int index = 0;
    for (int i = 0; i < 20; i++) {
        int input;
        bool flag1, flag2;
        do {
            flag1 = false;
            flag2 = false;
            cout << "Enter a number: ";
            cin >> input;

            if (!(input >= 10 && input <= 100)) {
                cout << "Invalid Input.." << endl;
                flag1 = true;
            }

            if (searchArray(arr, input, index)) {
                cout << "Invalid Input.." << endl;
                flag2 = true;
            }

        } while ((flag1 || flag2) && index < 20);

        arr[index++] = input;
    }
    applySort(arr, 20);
    printArray(arr, 20);
    system("pause");
    return 0;
}


void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}

bool searchArray(int array[], int x, int size) {
    int index = -1;
    for (int i = 0; i <= size; i++) {
        if (x == array[i])
            index = i;
    }

    if (index == -1)
        return false;
    else
        return true;
}

void applySort(int array[], int size) {
    for (int i = (size - 1); i >= 1; i--) {
        int max = 0;
        int j = 1;

        for (j; j <= i; j++) {
            if (array[max] < array[j])
                max = j;
        }
        //Swapping
        int temp;
        temp = array[i];
        array[i] = array[max];
        array[max] = temp;
    }
}

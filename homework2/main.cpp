#include <iostream>
#include <math.h>
#include <conio.h>

double* memory(int i)
{
    return new double[i];
}

void fill(double* array, int i)
{
    for (int ind = 0; ind < i; ind++)
    {
        array[ind] = 1 + rand()%100;
    }
}

void show(double* array, int i)
{
    std::cout << "Элeмeнты мaccивa: ";
    for (int ind = 0; ind < i; ind++) {
        std::cout << array[ind] << " ";
    }
    std::cout << std::endl;
}

void smena(int* arr, int size)
{
    for (int i = 0; i < size; i+=2)
    {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}

void deleteMemory(double* array)
{
    delete[] array;
}

int** memory_2(int** array, unsigned rows, unsigned columns) {
    for (unsigned i{}; i < rows; i++) {

        array[i] = new int[columns];
    }
    return array;
}

int** fill_2(int** array, unsigned rows, unsigned columns) {
    for (unsigned i{}; i < rows; i++) {

        for (unsigned j{}; j < columns; j++) {

            array[i][j] = 10 + rand() % 50;

        }
    }
    return array;
}

int** show_2(int** array, unsigned rows, unsigned columns) {
    for (unsigned i{}; i < rows; i++)
    {
        for (unsigned j{}; j < columns; j++)
        {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}

void deleteMemory_2(int** array, unsigned rows, unsigned columns) {
    for (unsigned i{}; i < rows; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

float summa(int num_1, int num_2){
    return num_1 + num_2;
}

float minus(int num_1, int num_2){
    return num_1 - num_2;
}

float multi(int num_1, int num_2){
    return num_1 * num_2;
}

float divide(int num_1, int num_2)
{
    float divide = num_1/num_2;
    return divide;
}


int main()
{
    /* Task 1.1 */
    const float value = 7;
    const float *ptr =  &value;
    std::cout<< ptr <<" " <<*ptr << std::endl;
    /* Task 1.2 */
    typedef long int* dasha;
    long int ooo = 12;
    dasha ptr3 = &ooo;
    std::cout<< ptr3 <<" " <<*ptr3 << std::endl;
    /* Task 1.3 */
    double daubi = 10;
    double *ptr1 = &daubi;
    std::cout<< ptr1 <<" " <<*ptr1 << std::endl;
    /* Task 1.4 */
    const short int polinochka = 20;
    const short int *ptr2 = &polinochka;
    std::cout<< ptr2 <<" " <<*ptr2 << std::endl;
    /* Task 1.5 */
    typedef const float* nikita;
    const float zxc = 237.328;
    nikita  ptr4 = &zxc;
    std::cout<< ptr4 <<" " <<*ptr4 << std::endl;
    /* Task 1.6 */
    typedef const char* yaya;
    const char sad_side = 97;
    yaya ptr5 = &sad_side;
    std::cout<< ptr5 <<" " <<*ptr5 << std::endl;
    /* Task 1.7 */
    double lol = 123;
    const double *ptr6 = &lol;
    std::cout<< ptr6 <<" " <<*ptr6 << std::endl;
    /* Task 1.8 */
    typedef const unsigned int* kol;
    unsigned int opera = 0;
    kol ptr7 = &opera;

    /* Task 2 */

    char choice;
    do {
        std::cout << "Enter size of array: ";
        int i = 0;
        std::cin >> i;

        double* arr = memory(i);

        fill(arr, i);

        show(arr, i);

        deleteMemory(arr);

        std::cout << "Сontinue (enter 'y' to continue)? ";
        std::cin >> choice;
    } while (choice == 'y');

    /* Task 3 */

    int* arr = new int[12];
    for (int i = 0; i < 12; i++) {
        arr[i] = i + 1;
    }

    std::cout << "Initial array :" << std::endl;
    for (int i = 0; i < 12; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    smena(arr, 12);

    std::cout << "Modified array :" << std::endl;
    for (int i = 0; i < 12; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    /* Task 4 */

    unsigned rows, columns;
    std::cout << "Enter amount of rows: " << std::endl;
    std::cin >> rows;
    std::cout << "Enter amount of columns: " << std::endl;
    std::cin >> columns;

    int** array{ new int* [rows] {} };

    array = memory_2(array, rows, columns);

    array = fill_2(array, rows, columns);

    std::cout << "Result for Task 4: " << std::endl;
    show_2(array, rows, columns);
    deleteMemory_2(array, rows, columns);

    /* Task 5 */

    int num_1 = 0;
    int num_2 = 0;
    char sign;
    float (*fcnPtr)(int, int) = nullptr;
    float result;
    while (true) {
        sign = ' ';
        std::cout << "Enter number 1: " << std::endl;
        std::cin >> num_1;
        std::cout << "Enter number 2: " << std::endl;
        std::cin >> num_2;
        std::cout << "Enter sign: " << std::endl;
        sign = _getch();

        if (sign == '+')
        {
            fcnPtr = summa;
        }
        else if (sign == '-')
        {
            fcnPtr = minus;
        }
        else if (sign == '*')
        {
            fcnPtr = multi;
        }
        else if (sign == '/')
        {
            fcnPtr = divide;
        }
        else if (sign == ' ')
        {
            break;
        }
        else
        {
            std::cout << "Entered wrong sign, enter correct sign: " << std::endl;
            continue;
        }
        result = fcnPtr(num_1, num_2);
        std::cout << "Result for Task 5: " << result << std::endl;
    }
    return 0;
}





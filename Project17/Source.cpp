#include <string>
#include <fstream>  // ������ � �������
#include <iostream>
#include <cstdlib> // ��� ��������� ��������� �����
#include <ctime>

using namespace std;


void write_arr(const string& filename, const int* arr, const int n)
{
    fstream fs;

    fs.open(filename, fstream::out);
    if (fs.is_open()) // ���������, ��� ���� ������� ������
    {
        fs << n << '\n';  // ���������� ������ �������
        for (int i = 0; i < n; i++)
            fs << arr[i] << ' '; // ���������� �������� ����� ������
        fs << '\n';

        fs.close(); // ��������� ����
    }
}

void read_arr(const string& filename, int*& arr, int& n)
{
    fstream fs;

    fs.open(filename, fstream::in);
    if (fs.is_open()) // ���������, ��� ���� ������� ������
    {
        fs >> n;  // ������ ������ �������
        arr = new int[n];
        for (int i = 0; i < n; i++)
            fs >> arr[i]; // ������ �� ����� �������������� ������� - ������ � ������� ������

        fs.close(); // ��������� ����
    }
}

void output_arr(const string& filename, int*& arr, int& n)
{
    ofstream fs;

    fs.open(filename, ofstream::out);
    if (fs.is_open()) // ���������, ��� ���� ������� ������
    {
        fs << n << '\n';  // ���������� ������ �������
        for (int i = 0; i < n; i++)
            fs << arr[i] << ' '; // ���������� �������� ����� ������
        fs << '\n';

        fs.close(); // ��������� ����
    }

}

void swap(int* a, int* b) // ������� ��� ����� ������� ���� ��������
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high)
{
    int pivot = arr[high];    // ������� �������
    int i = (low - 1);  // ������ ����������� ��������
    for (int j = low; j <= high - 1; j++)
    {
        // ���� ������� ������� ������ ��� ����� ��������
        if (arr[j] <= pivot)
        {
            i++;    // ����������� ������ ������������ ��������
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);

    }
}
void merge(int* arr1, int* arr2,int* res, int sizefull) //������� ������� ��������������� ��������
{
        int i = 0;
        int k = 0;
        int j = 0;
        while ((i < sizefull) && (j < sizefull))
        {
            if (arr1[i] < arr2[j])
            {
                res[k] = arr1[i];
                i++;
            }
            else
            {
                res[k] = arr2[j];
                j++;
            }
            k++;
        }
        while (i < sizefull) // ��������� ��������� �������� ������� arr1, ���� ��� ����
        {
            res[k] = arr1[i];
            i++;
            k++;
        }
        while (i < sizefull) // ��������� ��������� �������� ������� arr2, ���� ��� ����
        {
            res[k] = arr2[j];
            j++;
            k++;
        }
}
void printArray(int* arr, int sizefull)
{
    for (int k = 0; k < (2 * sizefull); k++)
    {
        cout << arr[k] << " ";

    }
}
void printArrayFull(int* arr, int sizefull)
{
    for (int k = 0; k < (4 * sizefull); k++)
    {
        cout << arr[k] << " ";

    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string filename1 = "array_data1.txt";
    string filename2 = "array_data2.txt";
    string filename3 = "array_data3.txt";
    string filename4 = "array_data4.txt";
    string filename5 = "bigdata.txt";
    const int size = 27000000;
    int* rand_arr1 = new int[size];
    int* rand_arr2 = new int[size];
    int* rand_arr3 = new int[size];
    int* rand_arr4 = new int[size];
    int* result1 = new int[size + size];
    int* result2 = new int[size + size];
    int* result3 = new int[size + size+ size + size];
        
    int lef_border = 300;
    int range_len = 100000; // ������ ������� = range_len + left_border
    for (int i = 0; i < size; i++)
    {
        rand_arr1[i] = lef_border + rand() % range_len; // ���������� ����� � ��������� ��������� � ���������� � ������
    }
    
    for (int i = 0; i < size; i++) 
    {
        rand_arr2[i] = lef_border + rand() % range_len; // ���������� ����� � ��������� ��������� � ���������� � ������
    }
    
    for (int i = 0; i < size; i++) 
    {
        rand_arr3[i] = lef_border + rand() % range_len; // ���������� ����� � ��������� ��������� � ���������� � ������
    }
    
    for (int i = 0; i < size; i++) 
    {
        rand_arr4[i] = lef_border + rand() % range_len; // ���������� ����� � ��������� ��������� � ���������� � ������
    }
        
                      
    write_arr(filename1, rand_arr1, size); // ���������� ������ � ����
    write_arr(filename2, rand_arr2, size); // ���������� ������ � ����
    write_arr(filename3, rand_arr3, size); // ���������� ������ � ����
    write_arr(filename4, rand_arr4, size); // ���������� ������ � ����
    
    int* array_from_file1 = nullptr;
    int* array_from_file2 = nullptr;
    int* array_from_file3 = nullptr;
    int* array_from_file4 = nullptr;
    int n = 0;
    read_arr(filename1, array_from_file1, n); // ������ ������ �� �����
    read_arr(filename2, array_from_file2, n); // ������ ������ �� �����
    read_arr(filename3, array_from_file3, n); // ������ ������ �� �����
    read_arr(filename4, array_from_file4, n); // ������ ������ �� �����
    
    quickSort(array_from_file1, 0, n-1); // ��������� ����������
    quickSort(array_from_file2, 0, n - 1);// ��������� ����������
    quickSort(array_from_file3, 0, n - 1);// ��������� ����������
    quickSort(array_from_file4, 0, n - 1);// ��������� ����������
        
    merge(array_from_file1, array_from_file2,result1,size); //������� ���� �������� � ����
    merge(array_from_file3, array_from_file4, result2, size); //������� ���� �������� � ����
    
    int p = 2 * size;
    merge(result1, result2, result3, p); //������� ���� �������� �������� � �������
        
    int o = 4 * size;
    output_arr(filename5, result3, o); //������ �������� ������� � ����

    delete[] rand_arr1;
    delete[] rand_arr2;
    delete[] rand_arr3;
    delete[] rand_arr4;
    delete[] array_from_file1;
    delete[] array_from_file2;
    delete[] array_from_file3;
    delete[] array_from_file4;
    delete[] result1;
    delete[] result2;
    delete[] result3;
    
    return 0;
}
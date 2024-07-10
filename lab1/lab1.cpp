#include <iostream>
using namespace std;

const int sz = 16;

template <typename T>
T bubble_sort(T arr_[], int sz){
    for(int i=0 ; i < sz - 1 ; i++)
    {
        for(int j = 0; j < sz - i - 1; j++)
        {
            if(arr_[j] > arr_[j+1])
            {
                T temp = arr_[j];
                arr_[j] = arr_[j+1];
                arr_[j+1] = temp;
            }
        }
    }
}

template <typename T>
void printarr(T arr[], int sz){
    for(int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
    
int main()
{
    int arr_i[] = {51, 28, 100, 85, 12, 87, 71, 62, 44, 12, 57, 49, 59, 99, 29, 51};
    float arr_f[] = {17.76, 17.05, 17.13, 12.59, 16.64, 12.38, 15.88, 16.20, 16.95, 16.73, 16.83, 11.57, 15.76, 13.49, 15.88, 17.92};
    std::string arr_s[] = {
        "TXWBxfYRsy",
        "xZ0yADSfPz",
        "hgbsTNklpb",
        "koItyjTgbp",
        "YUvSXobjC5",
        "1mx6Cp8Jmm",
        "yYzQ4r9Ufi",
        "69zBs6h4cL",
        "2HrG7jSl5Y",
        "6CouycGPxJ",
        "2AFZUzkd58",
        "TJOYEOvNqL",
        "4Q8RpSJtXG",
        "XaVxGXytDW",
        "atjHwsTyUC",
        "SiXVWYqKaT",
    };

    bubble_sort(arr_i, sz);
    printarr(arr_i, sz);

    bubble_sort(arr_f, sz);
    printarr(arr_f, sz);

    bubble_sort(arr_s, sz);
    printarr(arr_s, sz);

    return 0;
}
#include <iostream>
extern "C" {
    int _stdcall getmin(int* a, int len);
    int _stdcall getmax(int* a, int len);
}

int main()
{
    int arr[10] = { 13,42,212,56,78,99,6,78,9,20 };
    int x = getmin(arr, 10);
    int y = getmax(arr, 10);
    printf("%d", x + y);
    return 0;
}
#include <iostream>

int maxIndex (int a[], int len){
    int maxInd = 0;
    for (int i = 0; i < len; i++){
        if (a[i] > a[maxInd]){
            maxInd = i;
        }
    }
    return maxInd;
}

int main(void){
    int arr[10] = {3,24,82,12,34,7,53,17,26,51};
    int maxInd = maxIndex(arr, 10);
    std::cout << "배열 내 최댓값의 인덱스는 " << maxInd << "입니다 \n";
    return 0;
}
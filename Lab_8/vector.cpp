#include <iostream>
#include <vector>
using namespace std;

void printMemVec(const vector<int> &vec, int size){
    printf("vector - Each int is worth %u bytes\n", sizeof(vec[0]));
    for(int i = 0; i < vec.size(); i++){
        printf("Value: %i at Memory Location: %p\n", vec[i], &vec[i]);
    }
}

void incVecBy10(vector<int> &vec, int size){
    for(int i = 0; i < vec.size(); i++){
        vec[i] += 10;
    }
}

int main(){
    const int SIZE = 5;
    vector<int> vec(SIZE);
    for(int i = 0; i < SIZE; i++){
        vec[i] = 100 + i;
    }

    printf("Before------------\n");
    printMemVec(vec, SIZE);
    incVecBy10(vec, SIZE);
    printf("After------------\n");
    printMemVec(vec, SIZE);
    return 0;
}
# include <iostream>
# include <vector>
# include <fstream>
# include <ctime>
# include <chrono>
using namespace std;

template<typename T>
int iterativeSearch(vector<T>v, T elem){
    for (int i = 0; i < v.size(); i++){
        if (v[i] == elem){
            return i;
        }
    }

    return -1;
}

template<typename T>
int binarySearch(vector<T> &v, int startIndex, int endIndex, T elem){
    if (startIndex > endIndex){
        return -1;
    }

    int mid = (startIndex + endIndex) / 2;

    if (v[mid] > elem) {
        endIndex = mid - 1;
    }

    else if (v[mid] < elem) {
        startIndex = mid + 1;
    }

    else {
        return mid;
    }

    return binarySearch(v, startIndex, endIndex, elem);
}

template<typename T>
void vecGen(string filename, vector<T> & v){
    ifstream file(filename);
    T num;
    v.clear();
    while (file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}

int main(){
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    for(int i = 0; i < elem_to_find.size(); i++){
        int elem = elem_to_find[i];

        auto start = chrono::high_resolution_clock::now();
        int index_if_found = binarySearch(v, 0, v.size()-1, elem);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

        cout << index_if_found << ":" << duration.count() << endl;
    }

    vector<double> d;
    vecGen("1000_double.csv", d);
    vector<double> double_to_find;
    vecGen("double_to_find.csv", double_to_find);

    for(int i = 0; i < double_to_find.size(); i++){
        double elem = double_to_find[i];

        auto start = chrono::high_resolution_clock::now();
        int index_if_found = binarySearch(d, 0, d.size()-1, elem);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

    }
}
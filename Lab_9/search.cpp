# include <iostream>
# include <vector>
# include <fstream>
# include <ctime>
# include <chrono>

using namespace std;

int iterativeSearch(vector<int>v, int elem){
    for (int i = 0; i < v.size(); i++){
        if (v[i] == elem){
            return i;
        }
    }

    return -1;
}

int binarySearch(vector<int> & v, int startIndex, int endIndex, int elem){
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

void vecGen(string filename, vector<int> & v){
    ifstream file(filename);
    int num;
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

    cout << "\niterative search\n" << endl;

    for(int i = 0; i < elem_to_find.size(); i++){
        int elem = elem_to_find[i];

        auto start = chrono::high_resolution_clock::now();
        int index_if_found = iterativeSearch(v, elem);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

        cout << index_if_found << ":" << duration.count() << " microseconds" << endl;
    }

    cout << "\nbinary search\n" << endl;


    for(int i = 0; i < elem_to_find.size(); i++){
        int elem = elem_to_find[i];

        auto start = chrono::high_resolution_clock::now();
        int index_if_found = binarySearch(v, 0, v.size()-1, elem);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

        cout << index_if_found << ":" << duration.count() << " microseconds" << endl;
    }
}
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

void writeTimes(string filename, const vector<double> times, const vector<int> n){
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (sec) " << endl;
    for (int i = 0; i < times.size(); i++){

        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}

double average(vector <double> a){
    double average = 0.0;
    double sum = 0.0;
    
    for (int i = 0; i < a.size(); i++){
        sum = sum + a[i];
    }

    average = sum / a.size();
    return average;
}

int main(){
    // test elements to search for
    vector <int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    //n list of numbers
    vector<int> file_sizes;
    vecGen("sizes.csv", file_sizes);

    //n list of numbers
    vector<int>v;

    //results of times
    vector<double> times;

    //results of times
    vector<double> avg;

        for(int i = 0; i < file_sizes.size(); i++){
            
            string filename = to_string(file_sizes[i]) + "_numbers.csv";
            vecGen(filename, v);

            cout << filename << endl;

            times.clear();

            for(int j = 0; j < elem_to_find.size(); j++){
                int elem = elem_to_find[j];

                auto start = chrono::high_resolution_clock::now();
                int index_if_found = iterativeSearch(v, elem);
                auto end = chrono::high_resolution_clock::now(); 

                auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
                double duration_double = std::chrono::duration<double>(duration).count();

                cout << index_if_found << ":" << duration_double << endl;

                times.push_back(duration_double);
            }

            double average_times = average(times);

            times.push_back(average_times);   
        }

        writeTimes("iterativeSearch_Times.csv", times, file_sizes);
        
        avg.clear();

        for(int i = 0; i < file_sizes.size(); i++){
            string filename = to_string(file_sizes[i]) + "_numbers.csv";
            vecGen(filename, v);

            cout << filename << endl;

            times.clear();

            for(int j = 0; j < elem_to_find.size(); j++){
                int elem = elem_to_find[j];

                auto start = chrono::high_resolution_clock::now();
                int index_if_found = binarySearch(v, 0, v.size()-1, elem);
                auto end = chrono::high_resolution_clock::now(); 

                auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
                double duration_double = std::chrono::duration<double>(duration).count();

                cout << index_if_found << ":" << duration_double << endl;

                times.push_back(duration_double);
            }
        }
        
        writeTimes("binarySearch_times.csv", times, file_sizes);
}


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void bucketSort(string arr[], int N) {
	char min = 'A';
	char max = 'Z';
	int bucket[26][1000000];
	int bucket_size[26] = { 0 };
	for (int i = 0; i < N; i++) {
		bucket[arr[i][0] - 65][bucket_size[arr[i][0] - 65]] = i;
		bucket_size[arr[i][0] - 65] += 1;
	}
	for (int i = 0; i < 26; i++){
	    for(int j = 0; j < bucket_size[i]; j++){
	        cout << bucket[i][j] << endl;
	    }
	}

}


int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int N;
	fin >> N;
	string *arr = new string[N];
	
	for (int i = 0; i < N; ++i) {
		fin >> arr[i];
	}
		char min = 'A';
	char max = 'Z';
	int bucket[26][N];
	int bucket_size[26] = { 0 };
	for (int i = 0; i < N; i++) {
		bucket[arr[i][0] - 65][bucket_size[arr[i][0] - 65]] = i;
		bucket_size[arr[i][0] - 65] += 1;
	}
	int s;
	for (int i = 0; i < 26; i++){
	    for(int j = 0; j < bucket_size[i]; j++){
	        for(int k=j; k>0 && bucket[i][k-1]>bucket[i][k];k--){
    	        s = bucket[i][k];
    	        bucket[i][k] = bucket[i][k-1];
    	        bucket[i][k - 1] = s;
	        }
	    }
	}
	for (int i = 0; i < 26; i++){
	    for(int j = 0; j < bucket_size[i]; j++){
	        fout << arr[bucket[i][j]] << endl;
	    }
	}
}

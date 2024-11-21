#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;


bool not_in_ptlist(string val, string* seen, int size){
    bool test = true; int pos = 0;
    while (test && pos<size){
        test = ((seen[pos++]) != val);
    }
    return test;
}

int count_lones(string* lines, int N){
    string* seen = new string [N];
    int count = 0;
    int lones = 0;
    for (int i = 0; i<N; i++){
        //show_arr(seen, count);
        string val = lines[i];
        if ( not_in_ptlist(val, seen, count) ) {
            
            int n_occ = 1;
            seen[count++] = val;
            for (int j = i+1; j<N; j++) {
                if ( lines[j] == val ) n_occ++;
            }
            if ( n_occ %2 == 1) lones++ ;
        };
    };
    return lones;
}

int main()
{
    int N, M;
    cin >> N;
    cin >> M;

    string* lines = new string[N];
    cin.ignore();
    for (int line = 0; line<N; line++){
        getline(cin, lines[line]);
    };
    cout << count_lones(lines, N);
}

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/// \param n le nombre de boites
/// \param valeur la valeur du marché du jour
/// \param boites le contenu de chaque boite

int deux_parmi_n (int n) {
    return n*(n-1)/2;
}

void le_juste_etal(int n, int valeur, const vector<int>& boites) {
    int N = 0; // Le futur nombre de séries justes
    int S_part = 0;
    map<int,int> S_mod_count;
    
    for (int i = 0; i<n; i++){
        S_part = (S_part + boites[i]) % valeur;
        if (S_mod_count.find(S_part) == S_mod_count.end()) { //Clé non présente.
            S_mod_count[S_part] = 0;
        }
        S_mod_count[S_part] ++;
    }
    
    for (auto item : S_mod_count){
        int reste = item.first ; int val = item.second;
        if (reste == 0) N = ( N + deux_parmi_n(val+1)%1000000007 )%1000000007;
        else N = ( N + deux_parmi_n(val)%1000000007 )%1000000007;
    }
    cout << N << endl;
    /* TODO Afficher, sur une ligne, un unique entier : le nombre de séries
    justes modulo $1,000,000,007$.  */
}

int main() {
    int n; ///< le nombre de boites
    cin >> n;
    int valeur; ///< la valeur du marché du jour
    cin >> valeur;
    vector<int> boites(n); ///< le contenu de chaque boite
    for (int& i : boites)
        cin >> i;
    le_juste_etal(n, valeur, boites);
}

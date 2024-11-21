#include <iostream>
#include <vector>

/// \param n le nombre de boites
/// \param valeur la valeur du marché du jour
/// \param boites le contenu de chaque boite

int deux_parmi_n (int n) {
    return n*(n-1)/2;
}

void le_juste_etal(int n, int valeur, const std::vector<int>& boites) {
    int N = 0; // Le futur nombre de séries justes
    int S_part = 0;
    int* S_mod_count = new int [valeur];
    
    for (int reste = 0; reste < valeur; reste++){
        S_mod_count[reste] = 0;
    }
    
    for (int i = 0; i<n; i++){
        S_part = (S_part + boites[i]) % valeur;
        S_mod_count[S_part] ++;
    }
    
    for (int reste = 0; reste < valeur; reste++){
        if (reste == 0) N = (N + deux_parmi_n(S_mod_count[reste]+1))%1000000007;
        else N = (N + deux_parmi_n(S_mod_count[reste]))%1000000007;
    }
    std::cout << N << std::endl;
    /* TODO Afficher, sur une ligne, un unique entier : le nombre de séries
    justes modulo $1,000,000,007$.  */
}

int main() {
    int n; ///< le nombre de boites
    std::cin >> n;
    int valeur; ///< la valeur du marché du jour
    std::cin >> valeur;
    std::vector<int> boites(n); ///< le contenu de chaque boite
    for (int& i : boites)
        std::cin >> i;
    le_juste_etal(n, valeur, boites);
}

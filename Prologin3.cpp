#include <iostream>
#include <vector>

/// \param longueur la longueur (en mètres) du passage souterrain
/// \param tunnel le tableau représentant les zones sûres et les zones de danger du passage souterrain. Un chiffre par mètre : Un `0` correspond à une position dans une zone sûre, et un `1` correspond à une position dans une zone de danger

void show_list(int longueur, int* tunnel) {
    for (int i = 0; i < longueur; i++) {
        std::cout << tunnel[i];
    }
    std::cout << std::endl;
}


void force_maximale(int longueur, const std::vector<int>& tunnel) {
    int current_bloc = tunnel[0];
    int E = 0; int R = longueur;
    int longueur_courante = 1;
    for (int i = 1; i<longueur; i++){
        if (tunnel[i] == current_bloc) {
            longueur_courante++;
        }
        else {
            if (current_bloc == 0 && longueur_courante < R) {R = longueur_courante;}
            else if (current_bloc == 1 && longueur_courante > E) {E = longueur_courante;}

            longueur_courante = 1;
            current_bloc = 1 - current_bloc;
        }
    }
    if (current_bloc == 0 && longueur_courante < R) {R = longueur_courante;}
    else if (current_bloc == 1 && longueur_courante > E) {E = longueur_courante;}
    std::cout << R - E << std::endl;
}

// D'une part en déterminant la longueur maximale d'un obstacle on a la valeur de E
// D'autre part, en trouvant la longueur minimale d'une zone de repos on a la valeur de R.


int main() {
    int longueur; ///< la longueur (en mètres) du passage souterrain
    std::cin >> longueur;
    std::vector<int> tunnel(longueur); ///< le tableau représentant les zones sûres et les zones de danger du passage souterrain. Un chiffre par mètre : Un `0` correspond à une position dans une zone sûre, et un `1` correspond à une position dans une zone de danger

    for (int& i : tunnel)
        std::cin >> i;
    force_maximale(longueur, tunnel);
}

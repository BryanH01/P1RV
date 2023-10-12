#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;

int main() {
     /*Boucle de capture des frappes de clavier*/
    while (true) {
        bool couche = true;
        int touche = -1;
        // Mesure du début du temps d'appui (DT)
        auto start = std::chrono::high_resolution_clock::now();

        // Attendre jusqu'à ce que la touche soit relâchée (ou définir votre propre condition)
        // Par exemple, vous pouvez utiliser un événement clavier ou une autre condition
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
        while (couche) {
            for (int i = 0; i < 256; ++i) {
                if (GetAsyncKeyState(i) & 0x8000 && i != VK_SHIFT) {
                    //std::cout << "Key pressed: " << i << std::endl;
                    if (touche != i && touche > 0) {
                        couche = false;
                    }
                    touche = i;
                }
            }
        }

        //for (int i = 0; i < 256; ++i) {
        //    if (GetAsyncKeyState(i) & 0x8000 && i != VK_SHIFT) {
        //        //std::cout << "Key pressed: " << i << std::endl;
        //        break;
        //    }
        //}
        //auto dtEnd = std::chrono::high_resolution_clock::now();
       
        
        // Mesure de la fin du temps d'appui (DT)
        auto ftEnd = std::chrono::high_resolution_clock::now();

        // Calcul du temps d'appui (DT) en millisecondes
        double ft = std::chrono::duration<double, std::milli>(ftEnd - start).count();
        //double ft = std::chrono::duration<double, std::milli>(dtEnd - start).count();

        // Mesure du temps entre les touches (FT)
        if (ft > 0) {
            // Vous pouvez enregistrer ou afficher le temps d'appui (DT) et le temps entre les touches (FT) ici
            std::cout << "Temps d'appui (FT) : " << ft << " ms" << std::endl;
        }

        // Attendre un court laps de temps entre les captures (à adapter)
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Attendre pendant 10 millisecondes (à adapter)
    }

    while (true) {
        
    }

    return 0;
}

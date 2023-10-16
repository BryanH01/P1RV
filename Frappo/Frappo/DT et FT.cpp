#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;

int main2() {
    int touchePrecedente = -1;
    auto startDT = std::chrono::high_resolution_clock::now();

    while (true) {
        int toucheActuelle = -1;

        for (int i = 0; i < 256; ++i) {
            if (GetAsyncKeyState(i) & 0x8000) {
                // Enregistrez la touche actuelle qui est enfoncée
                toucheActuelle = i;
            }
        }
        

        //cout << !(GetAsyncKeyState(toucheActuelle) & 0x8000);
        if (touchePrecedente != -1 && !(GetAsyncKeyState(toucheActuelle) & 0x8000)) {
            auto endDT = std::chrono::high_resolution_clock::now();
            double dt = std::chrono::duration<double, std::milli>(endDT - startDT).count();
            std::cout << "Temps d'appui (DT) : " << dt << " ms" << std::endl;
        }
        if (toucheActuelle != -1) {
            if (toucheActuelle != touchePrecedente) {
                // Enregistrez le moment du pressage de la touche pour FT
                auto ftStart = std::chrono::high_resolution_clock::now();
                // Calculez le FT
                double ft = std::chrono::duration<double, std::milli>(ftStart - startDT).count();
                // Affichez les valeurs DT et FT
                std::cout << "Temps entre les touches (FT) : " << ft << " ms" << std::endl;
                startDT = std::chrono::high_resolution_clock::now();
                touchePrecedente = toucheActuelle;
            }
        }
        else {
            touchePrecedente = -1;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    return 0;
}

// Affichez les valeurs DT et FT
//std::cout << "Temps d'appui (DT) : " << dt << " ms" << std::endl;
//std::cout << "Temps entre les touches (FT) : " << ft << " ms" << std::endl;
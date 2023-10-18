#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include "Temps.h"
#include "FileHandler.h"

#include <shellapi.h>

using namespace std;

void test() {


    auto start = std::chrono::high_resolution_clock::now();
    vector<int> touches;
    vector<std::chrono::time_point<std::chrono::high_resolution_clock>> temps;

    while (true) {

        for (int i = 0; i < 256; ++i) {
            //if (i != 160 && i != 162 && i != 164 && i != 165)
            if (GetAsyncKeyState(i) & 0x8000) {
                // Enregistrez la touche actuelle qui est enfoncée
                cout << "touche : " << i << endl;
                vector<int>::iterator it = find(touches.begin(), touches.end(), i);
                if (it == touches.end()) {
                    touches.push_back(i);

                    auto end = std::chrono::high_resolution_clock::now();
                    // Calculez le FT
                    double ft = std::chrono::duration<double, milli>(end - start).count();
                    cout << "Temps entre les touches (FT) : " << ft << " ms" << endl;
                    temps.push_back(end);
                    start = std::chrono::high_resolution_clock::now();
                }
            }
        }

        for (int i = touches.size()-1; i >= 0; i--) {
            if (!(GetAsyncKeyState(touches[i]) & 0x8000)) {
                auto end = std::chrono::high_resolution_clock::now();
                touches.erase(touches.begin() + i);
                double dt = std::chrono::duration<double, milli>(end - temps[i]).count();
                cout << "Temps d'appui (DT) : " << dt << " ms" << endl;
                temps.erase(temps.begin() + i);
            }
        }
    }
}

void mesure(vector<double>* DT, vector<double>* FT) {
    cout << "Appuyez sur 'Entrée' pour terminer la mesure" << endl;
    ShellExecute(0, 0, L"https://www.ratatype.fr/typing-test/", 0, 0, SW_SHOW);

    auto start = std::chrono::high_resolution_clock::now();
    vector<int> touches;
    vector<std::chrono::time_point<std::chrono::high_resolution_clock>> temps;
    bool enCours = true;

    while (enCours) {
        if (GetAsyncKeyState(13) & 0x8000) { // Entrée, arrête la mesure
            enCours = false;
        }
        for (int i = 32; i < 256; ++i) {
            if (i != 160 && i != 162 && i != 164 && i != 165)
            if (GetAsyncKeyState(i) & 0x8000) {
                
                // Enregistrez la touche actuelle qui est enfoncée
                vector<int>::iterator it = find(touches.begin(), touches.end(), i);
                if (it == touches.end()) {
                    touches.push_back(i);

                    auto end = std::chrono::high_resolution_clock::now();
                    // Calculez le FT
                    double ft = std::chrono::duration<double, milli>(end - start).count();
                    // cout << "Temps entre les touches (FT) : " << ft << " ms" << endl;
                    FT->push_back(ft);
                    temps.push_back(end);
                    start = std::chrono::high_resolution_clock::now();
                }
            }
        }

        for (int i = touches.size() - 1; i >= 0; i--) {
            if (!(GetAsyncKeyState(touches[i]) & 0x8000)) {
                auto end = std::chrono::high_resolution_clock::now();
                touches.erase(touches.begin() + i);
                double dt = std::chrono::duration<double, milli>(end - temps[i]).count();
                // cout << "Temps d'appui (DT) : " << dt << " ms" << endl;
                DT->push_back(dt);
                temps.erase(temps.begin() + i);
            }
        }
    }
}

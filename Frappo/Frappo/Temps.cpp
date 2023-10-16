#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <vector>
#include "Temps.h"

using namespace std;

void test() {
    auto start = std::chrono::high_resolution_clock::now();
    vector<int> touches;
    vector<std::chrono::time_point<std::chrono::high_resolution_clock>> temps;

    while (true) {
        for (int i = 0; i < 256; ++i) {
            if (GetAsyncKeyState(i) & 0x8000) {
                // Enregistrez la touche actuelle qui est enfoncée
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

//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//// Structure pour repr�senter un exemple avec des caract�ristiques et une classe
//struct Example {
//    std::vector<double> features;
//    int label;
//};
//
//// Fonction pour calculer la distance euclidienne entre deux exemples
//double euclideanDistance(const Example& a, const Example& b) {
//    double sum = 0.0;
//    for (size_t i = 0; i < a.features.size(); ++i) {
//        double diff = a.features[i] - b.features[i];
//        sum += diff * diff;
//    }
//    return std::sqrt(sum);
//}
//
//// Fonction pour pr�dire la classe d'un nouvel exemple en utilisant K-NN
//int predictKNN(const std::vector<Example>& trainingData, const Example& newExample, int k) {
//    // Calculer les distances entre le nouvel exemple et tous les exemples d'entra�nement
//    std::vector<std::pair<double, int>> distances;
//    for (const Example& example : trainingData) {
//        double dist = euclideanDistance(newExample, example);
//        distances.push_back(std::make_pair(dist, example.label));
//    }
//
//    // Trier les distances en ordre croissant
//    std::sort(distances.begin(), distances.end());
//
//    // Compter les votes des k plus proches voisins
//    std::vector<int> classVotes(2, 0); // Supposons qu'il y ait deux classes (0 et 1)
//    for (int i = 0; i < k; ++i) {
//        int vote = distances[i].second;
//        classVotes[vote]++;
//    }
//
//    // Choisir la classe majoritaire
//    int predictedClass = (classVotes[0] > classVotes[1]) ? 0 : 1;
//    return predictedClass;
//}
//
//int main() {
//    // Exemples d'entra�nement
//    std::vector<Example> trainingData = {
//        {{1.0, 2.0}, 0}, // Exemple 1 (caract�ristiques, classe)
//        {{2.0, 3.0}, 0}, // Exemple 2
//        {{3.0, 4.0}, 1}, // Exemple 3
//        {{3.0, 2.0}, 1}, // Exemple 4
//        {{4.0, 2.0}, 1}  // Exemple 5
//    };
//
//    // Nouvel exemple � pr�dire
//    Example newExample = { {2.5, 3.0}, -1 }; // La classe sera pr�dite
//
//    int k = 3; // Valeur de K
//
//    // Pr�dire la classe du nouvel exemple
//    int predictedClass = predictKNN(trainingData, newExample, k);
//
//    std::cout << "La classe pr�dite est : " << predictedClass << std::endl;
//
//    return 0;
//}

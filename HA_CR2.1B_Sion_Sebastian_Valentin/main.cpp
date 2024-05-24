#include "Cities.h"

int main() {
    // Generarea automată a unei matrice de distanțe pentru 10 orașe
    int numCities = 10;
    int maxDistance = 9;
    vector<vector<int>> generatedDist = generateRandomMatrix(numCities, maxDistance);

    cout << "Matricea de distanțe generate automat:" << endl;
    for (const auto& row : generatedDist) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    auto bfsGeneratedResult = bfsTSP(generatedDist);
    cout << "Using BFS on generated matrix: " << bfsGeneratedResult.first << endl;
    cout << "Path: ";
    printPath(bfsGeneratedResult.second);

    auto ucsGeneratedResult = ucsTSP(generatedDist);
    cout << "Using UCS on generated matrix: " << ucsGeneratedResult.first << endl;
    cout << "Path: ";
    printPath(ucsGeneratedResult.second);

    auto aStarGeneratedResult = aStarTSP(generatedDist);
    cout << "Using A* on generated matrix: " << aStarGeneratedResult.first << endl;
    cout << "Path: ";
    printPath(aStarGeneratedResult.second);

    // Matrice de distanțe prestabilită pentru 10 orașe
    vector<vector<int>> presetDist = {
        {0, 2, 9, 10, 1, 6, 5, 7, 3, 4},
        {2, 0, 4, 3, 5, 9, 6, 2, 8, 7},
        {9, 4, 0, 2, 7, 1, 5, 3, 6, 8},
        {10, 3, 2, 0, 6, 8, 3, 2, 4, 7},
        {1, 5, 7, 6, 0, 2, 4, 8, 3, 5},
        {6, 9, 1, 8, 2, 0, 3, 5, 4, 7},
        {5, 6, 5, 3, 4, 3, 0, 2, 6, 5},
        {7, 2, 3, 2, 8, 5, 2, 0, 4, 6},
        {3, 8, 6, 4, 3, 4, 6, 4, 0, 2},
        {4, 7, 8, 7, 5, 7, 5, 6, 2, 0}
    };

    cout << "Matricea de distanțe prestabilită:" << endl;
    for (const auto& row : presetDist) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    auto bfsPresetResult = bfsTSP(presetDist);
    cout << "Using BFS on preset matrix: " << bfsPresetResult.first << endl;
    cout << "Path: ";
    printPath(bfsPresetResult.second);

    auto ucsPresetResult = ucsTSP(presetDist);
    cout << "Using UCS on preset matrix: " << ucsPresetResult.first << endl;
    cout << "Path: ";
    printPath(ucsPresetResult.second);

    auto aStarPresetResult = aStarTSP(presetDist);
    cout << "Using A* on preset matrix: " << aStarPresetResult.first << endl;
    cout << "Path: ";
    printPath(aStarPresetResult.second);

    return 0;
}
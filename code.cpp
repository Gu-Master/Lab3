#include <iostream>
#include <vector>
#include <cmath>

// Вычисление обычной корреляции между двумя массивами
double calculateCorrelation(const std::vector<int>& x, const std::vector<int>& y) {
    double meanX = 0, meanY = 0;
    for (int i = 0; i < x.size(); ++i) {
        meanX += x[i];
        meanY += y[i];
    }
    meanX /= x.size();
    meanY /= y.size();

    double numerator = 0, denominatorX = 0, denominatorY = 0;
    for (int i = 0; i < x.size(); ++i) {
        numerator += (x[i] - meanX) * (y[i] - meanY);
        denominatorX += std::pow(x[i] - meanX, 2);
        denominatorY += std::pow(y[i] - meanY, 2);
    }

    return numerator; // Обычная корреляция
}

// Вычисление нормализованной корреляции между двумя массивами
double calculateNormalizedCorrelation(const std::vector<int>& x, const std::vector<int>& y) {
    double meanX = 0, meanY = 0;
    for (int i = 0; i < x.size(); ++i) {
        meanX += x[i];
        meanY += y[i];
    }
    meanX /= x.size();
    meanY /= y.size();

    double numerator = 0, denominatorX = 0, denominatorY = 0;
    for (int i = 0; i < x.size(); ++i) {
        numerator += (x[i] - meanX) * (y[i] - meanY);
        denominatorX += std::pow(x[i] - meanX, 2);
        denominatorY += std::pow(y[i] - meanY, 2);
    }

    return numerator / std::sqrt(denominatorX * denominatorY); // Нормализованная корреляция
}

// Вывод результатов в виде таблицы
void printCorrelationTable(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c) {
    double corrAB = calculateCorrelation(a, b);
    double corrAC = calculateCorrelation(a, c);
    double corrBC = calculateCorrelation(b, c);

    double normCorrAB = calculateNormalizedCorrelation(a, b);
    double normCorrAC = calculateNormalizedCorrelation(a, c);
    double normCorrBC = calculateNormalizedCorrelation(b, c);

    std::cout << "Обычная корреляция между a, b и c:\n";
    std::cout << "   |  a  |  b  |  c  \n";
    std::cout << "a  |  -  | " << corrAB << " | " << corrAC << "\n";
    std::cout << "b  | " << corrAB << " |  -  | " << corrBC << "\n";
    std::cout << "c  | " << corrAC << " | " << corrBC << " |  -\n";

    std::cout << "\nНормализованная корреляция между a, b и c:\n";
    std::cout << "   |  a  |  b  |  c  \n";
    std::cout << "a  |  -  | " << normCorrAB << " | " << normCorrAC << "\n";
    std::cout << "b  | " << normCorrAB << " |  -  | " << normCorrBC << "\n";
    std::cout << "c  | " << normCorrAC << " | " << normCorrBC << " |  -\n";
}

int main() {
    std::vector<int> a = {4, 2, 8, -2, -4, -4, 1, 3};
    std::vector<int> b = {2, 1, 5, 0, -2, -3, 2, 4};
    std::vector<int> c = {-4, -1, -3, 1, 2, 5, -1, -2};

    printCorrelationTable(a, b, c);
    return 0;
}

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846264338327950288419716939937510;

void printHelp() {
    cout << "Тригонометрический калькулятор\n\n";
    cout << "Использование: ./calc -o <операция> [режим] <операнд>\n";
    cout << "Операции: tan (тангенс), cot (котангенс)\n";
    cout << "Режимы: --degrees (градусы, по умолчанию), --radians (радианы)\n";
    cout << "Пример: ./calc -o tan 45\n";
}

double toRadians(double degrees) {
    return degrees * PI / 180.0;
}

int main(int argc, char* argv[]) {
    if (argc < 3) { printHelp(); return 1; }

    string operation;
    string operandStr;
    bool inDegrees = true;
    bool hasOperand = false;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-o" && i + 1 < argc) { operation = argv[++i]; }
        else if (arg == "--degrees") { inDegrees = true; }
        else if (arg == "--radians") { inDegrees = false; }
        else if (arg == "-h" || arg == "--help") { printHelp(); return 0; }
        else if (!hasOperand) { operandStr = arg; hasOperand = true; }
        else { cerr << "Ошибка: слишком много операндов\n"; return 1; }
    }

    if (operation.empty() || operandStr.empty()) {
        cerr << "Ошибка: не указана операция или операнд\n"; return 1;
    }

    double operand;
    try { operand = stod(operandStr); }
    catch (...) { cerr << "Ошибка: неверный формат числа\n"; return 1; }

    double val = inDegrees ? toRadians(operand) : operand;
    double result = 0;

    if (operation == "tan") { result = tan(val); }
    else if (operation == "cot") {
        double t = tan(val);
        if (abs(t) < 1e-10) { cerr << "Ошибка: котангенс не определен\n"; return 1; }
        result = 1.0 / t;
    } else {
        cerr << "Ошибка: неизвестная операция (используйте tan или cot)\n"; return 1;
    }

    cout << fixed << setprecision(6) << result << endl;
    return 0;
}
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
void shift(int i, int count, double arrayint[], char arrayop[]) {
  for (int j = i + 1; j < count - 1; j++) {
    arrayint[j] = arrayint[j + 1];
  };
  for (int j = i; j < count - 2; j++) {
    arrayop[j] = arrayop[j + 1];
  };
}
double add(double x, double y) { return x + y; }
double sub(double x, double y) { return x - y; }
double mul(double x, double y) { return x * y; }
double div(double x, double y) { return x / y; }
int main(int argc, char *argv[]) {
  int count = 0;
  for (int i = 0; i < strlen(argv[1]); i++) {
    if ((argv[1][i] != '+') && (argv[1][i] != '-') && (argv[1][i] != '*') &&
        (argv[1][i] != '/'))
      count++;
  }
  double arrayint[count];
  int k = 0;
  for (int i = 0; i < strlen(argv[1]); i++) {
    if ((argv[1][i] != '+') && (argv[1][i] != '-') && (argv[1][i] != '*') &&
        (argv[1][i] != '/')) {
      arrayint[k] = (int)argv[1][i] - (int)'0';
      k++;
    }
  }
  char arrayop[count - 1];
  int m = 0;
  for (int i = 0; i < strlen(argv[1]); i++) {
    if ((argv[1][i] == '+') || (argv[1][i] == '-') || (argv[1][i] == '*') ||
        (argv[1][i] == '/')) {
      arrayop[m] = argv[1][i];
      m++;
    }
  }
  for (int i = 0; i < count - 1; i++) {
    if (arrayop[i] == '*') {
      arrayint[i] = mul(arrayint[i], arrayint[i + 1]);
      shift(i, count, arrayint, arrayop);
      count--;
    }
  }
  for (int i = 0; i < count - 1; i++) {
    if (arrayop[i] == '/') {
      arrayint[i] = div(arrayint[i], arrayint[i + 1]);
      shift(i, count, arrayint, arrayop);
      count--;
    }
  }
  for (int i = 0; i < count - 1; i++) {
    if (arrayop[i] == '+') {
      arrayint[i] = add(arrayint[i], arrayint[i + 1]);
      shift(i, count, arrayint, arrayop);
      count--;
    }
  }
  for (int i = 0; i < count - 1; i++) {
    if (arrayop[i] == '-') {
      arrayint[i] = sub(arrayint[i], arrayint[i + 1]);
      shift(i, count, arrayint, arrayop);
      count--;
    }
  }
  cout << arrayint[0];
}

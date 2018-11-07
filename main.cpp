#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void grad_matrix(ifstream &file, ofstream &file_result);
int** new_matrix(int n, int m, ifstream &file);

int main(int argc, char *argv[])
{
  ifstream file;
  ofstream file_result;
  file.open(argv[1]);
  file_result.open("result.txt");

  if (!file.is_open()) {
    cerr << "Не удалось открыть файл!" << endl;
    return 1;
  }

  while (!file.eof()) {
    grad_matrix(file, file_result);
  }

  file.close();
  file_result.close();

  return 0;
}

int** new_matrix(int n, int m, ifstream &file) {
  char data[20];

  // создаем двумерный динамический массив n на m
  // для хранения элементов матрицы и заполняем его данными из файла
  int** matrix = new int*[n];
  file >> data;

  for (int i=0;i<n;i++) {
    matrix[i] = new int[m];
    for (int j=0;j<m;j++,file >> data) {
      matrix[i][j] = atoi(data);
      cout << matrix[i][j] << " ";
    }
  }
  cout << endl;

  return matrix;
}

void grad_matrix(ifstream &file, ofstream &file_result) {
  char data[20];
  int m, n;

  // узнаем m и n
  file >> data;
  n = atoi(data);
  file >> data;
  m = atoi(data);

  int** matrix = new_matrix(n, m, file);

  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cout << matrix[i][j] << "  ";
    }
    cout << endl;
  }

  
}

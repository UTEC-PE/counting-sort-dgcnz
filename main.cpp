#include <cstdlib>
#include <iostream>

using namespace std;

void print(int numbers[], int size);
void countingSort(int numbers[], int size);

int main(int argc, char *argv[]) {
  int numbers[] = {1, 4, 1, 2, 7, 5, 2};
  int size = sizeof(numbers) / sizeof(*numbers);

  print(numbers, size);
  countingSort(numbers, size);
  print(numbers, size);

  system("read");
  return EXIT_SUCCESS;
}

void print(int numbers[], int size) {
  for (int i = 0; i < size; i++) {
    cout << numbers[i] << ' ';
  }
  cout << endl;
}

void countingSort(int numbers[], int size) {
  int max = 0;
  int *copy = new int[size];
  for (int h = 0; h < size; ++h) {
    copy[h] = numbers[h];
    if (max < numbers[h]) {
      max = numbers[h];
    }
  }

  int *count = new int[max + 1]();
  for (int i = 0; i < size; ++i) {
    count[numbers[i]]++;
  }

  int last = 0;
  for (int j = 0; j < max + 1; ++j) {
    count[j] += last;
    last = count[j];
  }

  for (int k = 0; k < size; ++k) {
    numbers[count[copy[k]] - 1] = copy[k];
    --count[copy[k]];
  }
}

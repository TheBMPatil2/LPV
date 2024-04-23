
#include <iostream>
#include <omp.h>
#define MAX 100
using namespace std;

void parallel_bubble_sort(int a[], int n);

void parallel_bubble_sort(int a[], int n) {
#pragma omp parallel
  {
    bool swapped = true;
    while (swapped) {
      swapped = false;
#pragma omp for
      for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
          swapped = true;
        }
      }
    }
  }
}

int main() {
  int a[MAX], n;

  cout << "Name: Bhagvat Mutthe" << endl;
  cout << "Roll No: BCB-76" << endl;

  cout << "\n Enter total number of elements: ";
  cin >> n;
  cout << "\n Enter the elements: ";
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << "\n Unsorted Elements: \n";
  for (int i = 0; i < n; i++) {
    cout << "\t" << a[i];
  }
  parallel_bubble_sort(a, n);
  cout << "\n Sorted array is: ";
  for (int i = 0; i < n; i++) {
    cout << "\t" << a[i];
  }
  return 0;
}

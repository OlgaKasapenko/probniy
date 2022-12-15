#include <iostream>
int arr[100000];
int arr2[100000];
int brr[100000];
int brr2[100000];
std::pair<int, int> Part(int left, int right) {
  std::pair<int, int> t;
  int opor_index = (left + right) / 2;
  int k = left;
  for (int i = left; i < right; i++) {
    if (arr[i] < arr[opor_index]) {
      arr2[k] = arr[i];
      brr2[k] = brr[i];
      k = k + 1;
    }
    t.first = k;
  }
  for (int i = left; i < right; i++) {
    if (arr[i] == arr[opor_index]) {
      arr2[k] = arr[i];
      brr2[k] = brr[i];
      k = k + 1;
    }
    t.second = k;
  }
  for (int i = left; i < right; i++) {
    if (arr[i] > arr[opor_index]) {
      arr2[k] = arr[i];
      brr2[k] = brr[i];
      k = k + 1;
    }
  }
  for (int i = left; i < right; i++) {
    arr[i] = arr2[i];
    brr[i] = brr2[i];
  }
  return t;
}

void Quick(int left, int right) {
  if (left == right) {
    return;
  }
  std::pair<int, int> pair1 = Part(left, right);
  Quick(left, pair1.first);
  Quick(pair1.second, right);
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i] >> brr[i];
  }
  Quick(0, n);
  int j = 0, i = 0, numb = -1;
  while (j < n) {
    numb++;
    brr2[numb] = brr[i];
    arr2[numb] = arr[i];
    while (arr[j] <= brr2[numb] && j < n) {
      if (brr[j] > brr2[numb]) {
        brr2[numb] = brr[j];
      }
      j++;
    }
    i = j;
  }
  std::cout << numb + 1 << std::endl;
  for (int i = 0; i <= numb; i++) {
    std::cout << arr2[i] << " " << brr2[i] << std::endl;
  }
}

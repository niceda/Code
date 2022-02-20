#include <iostream>
#include <cmath>
#include <cstring>
#include <memory>
using namespace std;
int GetMaxDigit(int *h, int len) {
  if (h == NULL) return 0;
  if (len < 1) return 0;

  int max = h[0];
  for (int i = 0; i < len; ++i) {
    if (h[i] > max) max = h[i];
  }
  int digit = 1;
  while (max / 10 != 0) {
    max /= 10;
    digit++;
  }
  return digit;
}

int GetReminder(int value, int digit) {
  int div = 1;
  for (int i = 1;i < digit; i++) {
    div *= 10;
  }
  return value / div % 10;
}

void RadixSort_LSD(int *h, int len) {
  if (h == NULL) return;
  if (len <= 1) return;

  int digit = GetMaxDigit(h, len);

  int count[10] = {0};
  int *temp = (int*)malloc(len * sizeof(int));
  for (int d = 1; d <= digit; d++) {
    memset(count, 0, sizeof(count));

    for (int i = 0; i < len; i++) {
      count[GetReminder(h[i], d)]++;
    }

    for (int i = 1; i < 10; i++) {
      count[i] += count[i-1];
    }

    for (int i = len - 1; i >= 0; i--) {
      int r = GetReminder(h[i], d);
      int index = count[r];
      temp[index-1] = h[i];
      count[r]--;
    }
    memcpy(h, temp, len * sizeof(int));
  }
  free(temp);
}

void RadixSort_LSD_Reverse(int *h, int len) {
  if (h == NULL) return;
  if (len <= 1) return;

  int digit = GetMaxDigit(h, len);
  int count[10] = {0};
  int *temp = (int*)malloc(len * sizeof(int));
  for (int d = 1; d <= digit; d++) {
    memset(count, 0, sizeof(count));
    for (int i = 0; i < len; i++) {
      count[GetReminder(h[i], d)]++;
    }
    for (int i = 8; i >= 0; i--) {
      count[i] += count[i+1];
    }
    for (int i = len - 1; i >= 0; i--) {
      int r = GetReminder(h[i], d);
      int index = count[r];
      temp[index-1] = h[i];
      count[r]--;
    }
    memcpy(h, temp, len * sizeof(int));
  }
  free(temp);
}

void _RadixSort_MSD(int *h, int begin, int end, int digit) {
  if (h == NULL) return;
  if (begin >= end) return;
  if (digit < 1) return;

  int start[10];
  int count[10] = {0};
  int *temp = (int*)malloc((end - begin + 1) * sizeof(int));
  
  for (int i = begin; i <= end; i++) {
    count[GetReminder(h[i], digit)]++;
  }
  memcpy(start, count, sizeof(start));

  for (int i = 1; i < 10; i++) {
    start[i] += start[i-1];
  }

  for (int i = end; i >= begin; i--) {
    int r = GetReminder(h[i], digit);
    int index = start[r];
    temp[index-1] = h[i];
    start[r]--;
  }
  memcpy(&h[begin], temp, (end - begin + 1) * sizeof(int));

  for (int i = 0; i < 10; i++) {
    if (count[i] > 1) {
      _RadixSort_MSD(h, start[i], start[i] + count[i] - 1, digit - 1);
    }
  }
} 

void RadixSort_MSD(int *h, int len) {
  if (h == NULL) return;
  if (len <= 1) return;

  int digit = GetMaxDigit(h, len);
  _RadixSort_MSD(h, 0, len - 1, digit);
}

void _RadixSort_MSD_Reverse(int *h, int begin, int end, int digit) {
  if (h == NULL) return;
  if (begin >= end) return;
  if (digit < 1) return;

  int start[10];
  int count[10] = {0}; 
  int *temp = (int*)malloc((end - begin + 1) * sizeof(int));

  for (int i = begin; i <= end; i++) {
    count[GetReminder(h[i], digit)]++;
  }

  memcpy(start, count, sizeof(start));

  for (int i = 8; i >= 0; i--) {
    start[i] += start[i+1];
  }

  for (int i = end;i >= begin; i--) {
    int r = GetReminder(h[i], digit);
    int index = start[r];
    temp[index-1] = h[i];
    start[r]--;
  }
  memcpy(&h[begin], temp, (end - begin + 1) * sizeof(int));

  for (int i = 0; i < 10; i++) {
    if (count[i] > 1) {
      _RadixSort_MSD_Reverse(h, start[i], start[i] + count[i] - 1, digit - 1);
    }
  }
}

void RadixSort_MSD_Reverse(int *h, int len) {
  if (h == NULL) return;
  if (len <= 1) return;

  int digit = GetMaxDigit(h, len);

  _RadixSort_MSD_Reverse(h, 0, len  -1, digit);
}

int main() {
  int v[4] = {3, 4, 1, 2};
  // RadixSort_LSD(v, 4);
  RadixSort_LSD_Reverse(v, 4);
  for (int i = 0; i < 4; i++) {
    cout << v[i] << " ";
  }
}

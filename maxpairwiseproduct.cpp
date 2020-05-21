#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long result = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
          if ((long long)numbers[first]) * numbers[second] > result){
            result = ((long long)(numbers[first])) * numbers[second];
          }
        }
    }

    return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers){
  int n = numbers.size();

  int max_index1 = -1;
  for (int first = 0; first < n; ++first){
    if ((max_index1 == -1) || (numbers[first] > numbers[max_index1])){
      max_index1 = first;
    }
  }

  int max_index2 = -1;
  for (int second = 0; second < n; ++second){
    if((second != max_index1) && ((max_index2 == -1) || (numbers[second] > numbers[max_index2]))){
      max_index2 = second;
    }
    cout << max_index1 << ' ' << max_index2 << "\n";
  }
  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers); << "\n";
    return 0;
}

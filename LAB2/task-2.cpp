#include<iostream>
#include<vector>
using namespace std;

void MSI(vector<int>& array, int s, int m, int e) {
    vector<int> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e) {

        if (array[i] <= array[j]) {
            temp.push_back(array[i]);
            i++;
        }
        else {
            temp.push_back(array[j]);
            j++;
        }

    }

    while (i <= m) {
        temp.push_back(array[i]);
        i++;
    }

    while (j <= e) {
        temp.push_back(array[j]);
        j++;
    }

    for (int i = s; i <= e; ++i)
        array[i] = temp[i - s];

}

void MS(vector<int>& array, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        MS(array, s, m);
        MS(array, m + 1, e);
        MSI(array, s, m, e);
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> array(n);

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    MS(array, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << array[i] << ' ';
    }

}

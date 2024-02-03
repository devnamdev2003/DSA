#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>
#include<algorithm>
#include<map>

using namespace std;

struct Gear {
    double x, y, r;
};

int main() {
    int n;
    cin >> n;

    vector<Gear> gears(n);

    for (int i = 0; i < n; ++i) {
        cin >> gears[i].x >> gears[i].y >> gears[i].r;
    }

    double rotations = 1.0;

    for (int i = 0; i < n - 1; ++i) {
        double ratio = gears[i].r / gears[i + 1].r;
        rotations *= ratio;
    }

    if (rotations > 0) {
        cout << fixed << setprecision(2) << rotations << endl;
    } else {
        cout << "Could Not Process" << endl;
    }

    return 0;
}

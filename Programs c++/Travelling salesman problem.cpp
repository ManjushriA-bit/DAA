#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

const int N = 4;  // number of cities

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int dp[1 << N][N];

int tsp(int mask, int pos) {
    // if all cities visited, return cost to go back to start
    if (mask == (1 << N) - 1)
        return dist[pos][0];

    // if already computed
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // try visiting unvisited cities
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] +
                         tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cout << "Minimum travelling cost: " << tsp(1, 0);

    return 0;
}
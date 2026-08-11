#include <iostream>
#include <string>
#include "Orderqueue.cpp"
using namespace std;

const int MAX_STATIONS = 5;

string stations[MAX_STATIONS];
int stationMatrix[MAX_STATIONS][MAX_STATIONS] = {0};
int stationCount = 0;

void addStation(string name) {
    if (stationCount < MAX_STATIONS) {
        stations[stationCount] = name;
        stationCount++;
    }
}

int getStationIndex(string name) {
    for (int i = 0; i < stationCount; i++) {
        if (stations[i] == name) return i;
    }
    return -1;
}

void connectStations(string source, string dest, int time) {
    int u = getStationIndex(source);
    int v = getStationIndex(dest);
    if (u != -1 && v != -1) {
        stationMatrix[u][v] = time;
    }
}

// BFS
void trackFoodPandaOrder(string startStation) {
    int startIdx = getStationIndex(startStation);
    if (startIdx == -1) {
        cout << "Station not found!" << endl;
        return;
    }

    bool visited[MAX_STATIONS] = {false};
    OrderQueue q;

    q.push(startIdx);
    visited[startIdx] = true;

    cout << "\n====================================================\n";
    cout << "     FOODPANDA LIVE ORDER DISPATCH SYSTEM (BFS)     \n";
    cout << "====================================================\n";
    cout << "ORDER ORIGIN: " << startStation << "\n\n";

    int stage = 1;
    int totalTravelTime = 0;

    while (!q.isEmpty()) {
        int currentSize = 0;
        Node* curr = q.front;
        while (curr != NULL) {
            currentSize++;
            curr = curr->next;
        }

        cout << "--- STAGE " << stage << " ---\n";
        for (int i = 0; i < currentSize; i++) {
            int currentStation = q.pop();
            cout << " [STATUS]: Order active at -> " << stations[currentStation] << "\n";

            for (int next = 0; next < stationCount; next++) {
                if (stationMatrix[currentStation][next] > 0 && !visited[next]) {
                    int stepTime = stationMatrix[currentStation][next];
                    totalTravelTime += stepTime;
                    cout << "   ↳ Transiting to " << stations[next] 
                         << " (Est. Time: +" << stepTime << " mins)\n";
                         
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        stage++;
        cout << "\n";
    }

    cout << "====================================================\n";
    cout << " SUCCESS: Order Handed to Customer!\n";
    cout << " TOTAL ESTIMATED DELIVERY TIME: " << totalTravelTime << " Minutes\n";
    cout << "====================================================\n";
}

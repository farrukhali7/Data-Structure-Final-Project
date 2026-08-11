#include <iostream>
#include <string>
#include "graph.cpp"
using namespace std;

int main() {
    addStation("Order Confirmed");    
    addStation("Kitchen Preparation");
    addStation("Packing & Quality");  
    addStation("Rider Picked Up");    
    addStation("Delivered to Door");  

    connectStations("Order Confirmed", "Kitchen Preparation", 5);
    connectStations("Kitchen Preparation", "Packing & Quality", 12);
    connectStations("Packing & Quality", "Rider Picked Up", 3);
    connectStations("Rider Picked Up", "Delivered to Door", 15);

    trackFoodPandaOrder("Order Confirmed");
}

#include "RideAnalytics.h"

extern vector<Trip> sampleTrips;


// Functions from RevenueAnalysis.cpp
void calculateTotalRevenue(RideAnalytics &analytics);
void revenueRangeQuery(RideAnalytics &analytics);
void averageRevenue(RideAnalytics &analytics);
void maximumRevenuePeriod(RideAnalytics &analytics);

// Functions from SearchAndFilter.cpp
void searchTripsByFare(RideAnalytics &analytics);
void findCheapestRide(RideAnalytics &analytics);
void removeCancelledTrips(RideAnalytics &analytics);
void filterRidesByZone(RideAnalytics &analytics);
void filterRidesByRating(RideAnalytics &analytics);

// Functions from DriverAnalytics.cpp
void driverStatistics(RideAnalytics &analytics);
void sortDriversByRating(RideAnalytics &analytics);
void topDrivers(RideAnalytics &analytics);
void highestRatedDriver(RideAnalytics &analytics);
void countHighRatedTrips(RideAnalytics &analytics);

// Functions from SurgePricing.cpp
void surgePricing(RideAnalytics &analytics);
void zoneAnalysis(RideAnalytics &analytics);
void report(RideAnalytics &analytics);


int main()
{
    RideAnalytics analytics;

    for(Trip trip : sampleTrips)
   {
         analytics.addTrip(trip);
   }

    int choice;

    do
    {
        cout << "\n==========================================";
        cout << "\n      RIDE SHARING ANALYTICS SYSTEM";
        cout << "\n==========================================";

        cout << "\n1. Display All Trips";
        cout << "\n2. Calculate Total Revenue";
        cout << "\n3. Revenue Range Query (Prefix Sum)";
        cout << "\n4. Average Revenue (Sliding Window)";
        cout << "\n5. Maximum Revenue Period (Kadane)";
        cout << "\n6. Search Trips By Fare";
        cout << "\n7. Find Cheapest Ride";
        cout << "\n8. Remove Cancelled Trips";
        cout << "\n9. Filter Trips By Zone";
        cout << "\n10. Filter Trips By Rating";
        cout << "\n11. Driver Statistics";
        cout << "\n12. Sort Drivers By Rating";
        cout << "\n13. Top Drivers";
        cout << "\n14. Highest Rated Driver";
        cout << "\n15. Count High Rated Trips";
        cout << "\n16. Apply Surge Pricing";
        cout << "\n17. Zone wise Analysis";
        cout << "\n18. Generate Report";
        cout << "\n0. Exit";

        cout << "\n\nEnter Choice : ";
        cin >> choice;

        cout << endl;

        switch(choice)
        {
        case 1:
            analytics.displayTrips();
            break;

        case 2:
            calculateTotalRevenue(analytics);
            break;

        case 3:
            revenueRangeQuery(analytics);
            break;

        case 4:
            averageRevenue(analytics);
            break;

        case 5:
            maximumRevenuePeriod(analytics);
            break;

        case 6:
            searchTripsByFare(analytics);
            break;

        case 7:
            findCheapestRide(analytics);
            break;

        case 8:
            removeCancelledTrips(analytics);
            break;

        case 9:
            filterRidesByZone(analytics);
            break;

        case 10:
            filterRidesByRating(analytics);
            break;

        case 11:
            driverStatistics(analytics);
            break;

        case 12:
            sortDriversByRating(analytics);
            break;

        case 13:
            topDrivers(analytics);
            break;

        case 14:
            highestRatedDriver(analytics);
            break;

        case 15:
            countHighRatedTrips(analytics);
            break;

        case 16:
            surgePricing(analytics);
            break;
        
        case 17:
            zoneAnalysis(analytics);
            break;

        case 18:
            report(analytics);
            break;    
        case 0:
            cout << "\nThank you for using Ride Sharing Analytics!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 0);

    return 0;

}

#include "../Trip.h"
#include "../RideAnalytics.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <iostream>

using namespace std;

/*
1. Binary Search
2. min_element
3. remove + erase
*/

// Binary Search
void searchTripsByFare(RideAnalytics &analytics)
{
    vector<Trip> trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    sort(trips.begin(), trips.end(), [](Trip a, Trip b)
    {
        return a.fare < b.fare;
    });

    double fare;

    cout << "\n----- Search Trip By Fare -----" << endl;
    cout << "Enter Fare : ";
    cin >> fare;

    int left = 0;
    int right = trips.size() - 1;
    bool found = false;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(trips[mid].fare == fare)
        {
            cout << "\nTrip Found!" << endl;
            cout << "Ride ID : " << trips[mid].rideID << endl;
            cout << "Driver ID : " << trips[mid].driverID << endl;
            cout << "Fare : " << trips[mid].fare << endl;
            cout << "Rating : " << trips[mid].rating << endl;
            cout << "Zone : " << trips[mid].zone << endl;

            found = true;
            break;
        }
        else if(trips[mid].fare < fare)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if(!found)
    {
        cout << "Trip Not Found!" << endl;
    }
}


// min_element
void findCheapestRide(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    if(trips.empty())
    {
        cout << "No Trips Available!" << endl;
        return;
    }

    auto cheapest = min_element(trips.begin(), trips.end(), [](Trip a, Trip b)
    {
        return a.fare < b.fare;
    });

    cout << "\n----- Cheapest Ride -----" << endl;
    cout << "Ride ID : " << cheapest->rideID << endl;
    cout << "Driver ID : " << cheapest->driverID << endl;
    cout << "Fare : " << cheapest->fare << endl;
    cout << "Rating : " << cheapest->rating << endl;
    cout << "Zone : " << cheapest->zone << endl;
    cout << "Distance : " << cheapest->distance << endl;
}


// remove + erase
void removeCancelledTrips(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    int before = trips.size();

    trips.erase(remove_if(trips.begin(), trips.end(), [](Trip trip)
    {
        return trip.cancelled;
    }), trips.end());

    int after = trips.size();

    cout << "\n----- Remove Cancelled Trips -----" << endl;
    cout << "Trips Removed : " << before - after << endl;
    cout << "Remaining Trips : " << after << endl;
}


// Filter By Zone
void filterRidesByZone(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();
    string targetZone;
    cout << "Enter Zone: ";
    cin >> targetZone;

    bool found = false;

    targetZone = toLower(targetZone);

    for (Trip t : trips)
    {
        if (toLower(t.zone) == targetZone)
        {
            found = true;

            cout <<"RideID : "<< t.rideID << " , "
                 << "DriverID : " << t.driverID << " , "
                 << "Fare : " << t.fare << " , "
                 << "Zone : " << t.zone << " , "
                 << "Rating : " << t.rating << endl;
        }
    }

    if (!found)
        cout << "No Ride Found\n";
}


void filterRidesByRating(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();
    double targetRating;
    cout << "Enter Rating: ";
    cin >> targetRating;

    bool found = false;

    for (Trip t : trips)
    {
        if (t.rating >= targetRating)
        {
            found = true;

            cout <<"RideID : "<< t.rideID << " , "
                 << "DriverID : " << t.driverID << " , "
                 << "Fare : " << t.fare << " , "
                 << "Zone : " << t.zone << " , "
                 << "Rating : " << t.rating << endl;
        }
    }

    if (!found)
        cout << "No Ride Found\n";
}



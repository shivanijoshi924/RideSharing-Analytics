#include "../Trip.h"
#include "../RideAnalytics.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <iostream>
/*
1. Binary Search
2. min_element
3. remove + erase
*/
 
string toLower(string str)
{
    for (char &ch : str)
    {
        ch = tolower(ch);
    }
    return str;
}

void searchTripsByFare(RideAnalytics &analytics)
{
     vector<Trip> &trips = analytics.getTrips();

     sort(trips.begin(), trips.end(),
         [](Trip a, Trip b)
         {
             return a.fare < b.fare;
         });

    double targetFare;

    cout << "Enter Fare: ";
    cin >> targetFare;

    int low = 0;
    int high = trips.size() - 1;

    while (low <= high)
    {
        int mid = (high + low) / 2;

        if (trips[mid].fare == targetFare)
        {
            cout << "Ride Found\n";
            cout << "Ride ID : " << trips[mid].rideID << endl;
            cout << "Driver ID : " << trips[mid].driverID << endl;
            cout << "Fare : " << trips[mid].fare << endl;
            cout << "Zone : " << trips[mid].zone << endl;
            cout << "Rating : " << trips[mid].rating << endl;
            return;
        }

        else if (trips[mid].fare < targetFare)
            low = mid + 1;

        else
            high = mid - 1;
    }

    cout << "Ride Not Found\n";
}

void findCheapestRide(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    auto cheapest = min_element(trips.begin(), trips.end(),
                                [](Trip a, Trip b)
                                {
                                    return a.fare < b.fare;
                                });

    if (cheapest != trips.end())
    {
        cout << "Cheapest Ride\n";
        cout << "Ride ID : " << cheapest->rideID << endl;
        cout << "Fare : " << cheapest->fare << endl;
        cout << "Zone : " << cheapest->zone << endl;
    }
}

void removeCancelledTrips(RideAnalytics &analytics)
{
    vector<Trip> &trips = analytics.getTrips();

    trips.erase(remove_if(trips.begin(), trips.end(),
                          [](Trip trip)
                          {
                              return trip.cancelled;
                          }),
                trips.end());
}

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



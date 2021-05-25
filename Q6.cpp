#include <iostream>
using namespace std;

struct Runway
{
	int id;
	string type;
	bool availability;
	int dur;
	int s_Time; //start time of each task
};

class Flight
{
private:
	string flight_No, date;		   //
	double arrivalTime;			   //arrival time which is known at the departure.
	double remaingFlyTime;		   //how long can the fuel last it no runway is available
	double scheduled_landing_Time; //
	Runway rn;					   //
public:
	void addFlight();						//function to add flight information
	void UpdateRemainingFlyTime(double);	//This is updated once the flight contacts AirController
	void UpdateLandingInfo(double, Runway); //get landing time from the AirController depending on the availability of the runway
	string getFlightNo();
	string getFlightDate();
	double getFlightArrivalTime();
	double getRemainingTimeFly();
	double getScheduledLandingTime();
	Runway getRunway();
};

string Flight ::getFlightNo()
{
	return flight_No;
}

string Flight ::getFlightDate()
{
	return date;
}

double Flight ::getFlightArrivalTime()
{
	return arrivalTime;
}

double Flight ::getRemainingTimeFly()
{
	return remaingFlyTime;
}

double Flight ::getScheduledLandingTime()
{
	return scheduled_landing_Time;
}

Runway Flight ::getRunway()
{
	return rn;
}

void Flight ::addFlight()
{
	cout << "Enter flight No: ";
	getline(cin, flight_No);
	cin.clear();
	cout << "Enter Date: ";
	getline(cin, date);
	cin.clear();
	cout << "Enter Arrival time: ";
	cin >> arrivalTime;
	cout << "Enter Scheduled Landing time: ";
	cin >> scheduled_landing_Time;
}

void Flight ::UpdateRemainingFlyTime(double updatedRemainingFlyTime)
{
	remaingFlyTime = updatedRemainingFlyTime;
}

void Flight ::UpdateLandingInfo(double updatedScheduledLandingTime, Runway runwayAssigned)
{
	scheduled_landing_Time = updatedScheduledLandingTime;
	rn = runwayAssigned;
}

class AirController
{
private:
	Runway runways[3];
	Flight *flightsContactedAirController;
	int totalFlights;
	const int numOfRunways = 3;

public:
	// constructors
	AirController(Flight flights[], int noOfFlights)
	{
		totalFlights = noOfFlights;
		flightsContactedAirController = new Flight[totalFlights];
		flightsContactedAirController = flights;
		// initalizing runways
		for (int i = 0; i < numOfRunways; i++)
		{
			runways[i].id = i + 1;
			runways[i].type = "Visual Runway";
			runways[i].availability = true; // initially all the runways are available
			runways[i].dur = 2;				// given that runway will be occupied for 2 minute duration for each landing of plane
			runways[i].s_Time = 1720;		// assigning start time to 17:20 initially however this may change during assigning the runways to each flight
		}
	}
	void RunwayStatus();  //prints the status of all the runways
	void FlightContact(); // prints the data of flights who have contacted the controller
	void AssignRunways(); // assigns runway to a flight
};

void AirController ::RunwayStatus()
{
	const string available = "available";
	const string notAvailable = "not available";
	cout << "Runaway No : 1 is currently " << runways[0].availability ? available : notAvailable;
	cout << endl
		 << "Runaway No : 2 is currently " << runways[1].availability
		? available
		: notAvailable;
	cout << endl
		 << "Runaway No : 3 is currently " << runways[2].availability
		? available
		: notAvailable;
	cout << endl;
}

void AirController ::FlightContact()
{
	for (int i = 0; i < totalFlights; i++)
	{
		cout << "Flight No : " << flightsContactedAirController[i].getFlightNo() << endl;
		cout << "Date : " << flightsContactedAirController[i].getFlightDate() << endl;
		cout << "Arrival time : " << flightsContactedAirController[i].getFlightArrivalTime() << endl;
		cout << "Remaining time fly : " << flightsContactedAirController[i].getRemainingTimeFly() << endl;
		cout << "Scheduled landing time : " << flightsContactedAirController[i].getScheduledLandingTime() << endl;
		cout << "Runway assigned : " << flightsContactedAirController[i].getRunway().id << endl;
		cout << endl
			 << "                              -------------------                    " << endl
			 << endl;
	}
}

void AirController ::AssignRunways()
{
	for (int i = 0; i < totalFlights; i++)
	{
		if (runways[0].availability)
		{
			double RTF = flightsContactedAirController[i].getScheduledLandingTime() - runways[0].s_Time;
			flightsContactedAirController[i].UpdateRemainingFlyTime(RTF);
			runways[0].availability = false; // generially for the next two minutes it would not be available
			flightsContactedAirController[i].UpdateLandingInfo(flightsContactedAirController[i].getScheduledLandingTime(), runways[0]);
		}
		else if (runways[1].availability)
		{
			double RTF = flightsContactedAirController[i].getScheduledLandingTime() - runways[1].s_Time;
			flightsContactedAirController[i].UpdateRemainingFlyTime(RTF);
			runways[1].availability = false; // generially for the next two minutes it would not be available
			flightsContactedAirController[i].UpdateLandingInfo(flightsContactedAirController[i].getScheduledLandingTime(), runways[1]);
		}
		else if (runways[2].availability)
		{
			double RTF = flightsContactedAirController[i].getScheduledLandingTime() - runways[2].s_Time;
			flightsContactedAirController[i].UpdateRemainingFlyTime(RTF);
			runways[2].availability = false; // generially for the next two minutes it would not be available
			flightsContactedAirController[i].UpdateLandingInfo(flightsContactedAirController[i].getScheduledLandingTime(), runways[2]);
		}
	}
}

int main()
{
	Flight flights[3];
	// we are assuming that 1720 is the starting time of each task generally however this may change during run time environment accroding to the specifiactions and requirements
	for (int i = 0; i < 3; i++)
	{
		flights[i].addFlight();
		cout << "          ----------------          " << endl;
		cin.clear();
		cin.ignore();
	}
	AirController airController(flights, 3);
	airController.AssignRunways();
	airController.FlightContact();
	return 0;
}

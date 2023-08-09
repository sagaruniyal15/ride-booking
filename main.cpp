#include "tripMgr.cpp"
#include "strategyMgr.cpp"
#include "riderMgr.cpp"
#include "driverMgr.cpp"
#include<iostream>

int main() {
	
	RiderMgr* riderMgr = RiderMgr::getRiderMgr();
	DriverMgr* driverMgr = DriverMgr::getDriverMgr();
	TripMgr* tripMgr = TripMgr::getTripMgr();

	while(true){
		cout << "Menu:" << std::endl;
        cout << "1. Add Rider" <<endl;
        cout << "2. Add Driver" <<endl;
        cout << "3. Create Trip" <<endl;
        cout << "4. Display All Trips" <<endl;
        cout << "5. Exit" <<endl;

		int choice;
        cout << "Select an option: ";
        cin >> choice;
		switch (choice)
		{
		case 1: {
			string ridername;
			cout<<"Enter Rider's name : ";
			cin>>ridername;
			Rider* newRider = new Rider(ridername, RATING::FOUR_STARS);
			riderMgr->addRider(ridername, newRider);
			cout<<"Rider added!"<<endl;
			break;
		}
		case 2: {
			string driverName;
            cout << "Enter driver's name: ";
            cin >> driverName;
            // Create a new Driver object and add it to the DriverMgr
            Driver* newDriver = new Driver(driverName, RATING::FOUR_STARS);
            driverMgr->addDriver(driverName, newDriver);

            cout << "Driver added!" <<endl;
            break;
		}
		case 3: {
			string name;
			cout<<"for whom you want to create the trip : ";
			cin>>name;
			cout << endl << "Creating Trip for "<<name<<" from location (200,200) to (500,500)" << endl;
			tripMgr->CreateTrip(riderMgr->getRider(name), new Location(10, 10), new Location(30, 30));
			cout<<"trip created"<<endl;
			break;
		}
		case 4: {
			unordered_map<int, Trip*> tripsMap = tripMgr->getTripsMap();
			for (auto mapVal : tripsMap) {
				(mapVal.second)->displayTripDetails();
			}
			break;
		}
		case 5: {
			cout<<"Exiting.........."<<endl;
			return 0;
		}
		default:
			cout<<"Invalid Choice..... Please enter again"<<endl;
			break;
		}

	}

	// //---------------Creating Riders and Drivers--------------------------------
	// Rider* SagarRider = new Rider("Sagar", RATING::FIVE_STARS);
	// Rider* PalakRider = new Rider("Palak", RATING::THREE_STARS);
	
	// riderMgr->addRider("Sagar", SagarRider);
	// riderMgr->addRider("Palak", PalakRider);

	// Driver* RohanDriver = new Driver("Rohan", RATING::THREE_STARS);
	// Driver* NamitaDriver = new Driver("Namita", RATING::FOUR_STARS);
	
	// driverMgr->addDriver("Rohan", RohanDriver);
	// driverMgr->addDriver("Namita", NamitaDriver);

	// //-------------------------------------------------------------------------

	


	// cout << endl << "Creating Trip for Sagar from location (10,10) to (30,30)" << endl;
	// tripMgr->CreateTrip(SagarRider, new Location(10, 10), new Location(30, 30));

	// cout << endl << "Creating Trip for Palak from location (200,200) to (500,500)" << endl;
	// tripMgr->CreateTrip(PalakRider, new Location(200, 200), new Location(500, 500));


	// //-------------------Display all the trips created--------------------------
	

	return 0;
}
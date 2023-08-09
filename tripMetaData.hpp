#pragma once
#include "rider.hpp"
#include "driver.hpp"

class TripMetaData {
	Location* srcLoc;
	Location* dstLoc;
	RATING riderRating;
	RATING driverRating;
public:
	TripMetaData(Location* pSrcLoc, Location* pDstLoc, RATING pRiderRating) :
		srcLoc(pSrcLoc), dstLoc(pDstLoc), riderRating(pRiderRating) {
		driverRating = RATING::UNASSIGNED;
	}

	RATING getRiderRating() {
		return riderRating;
	}
	RATING getDriverRating() {
		return driverRating;
	}
	void setDriverRating(RATING pDriverRating) {
		driverRating = pDriverRating;
	}
};

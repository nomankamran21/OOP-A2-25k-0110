#include "CarFeatures.h"


CarFeatures::CarFeatures()
    : hasAC(false), hasSunroof(false), hasNavigation(false),
      hasLeatherSeats(false), hasBackupCamera(false) {}
CarFeatures::CarFeatures(bool ac, bool sunroof, bool nav, bool leather, bool cam)
    : hasAC(ac), hasSunroof(sunroof), hasNavigation(nav),
      hasLeatherSeats(leather), hasBackupCamera(cam) {}


CarFeatures::CarFeatures(const CarFeatures& f)
    : hasAC(f.hasAC), hasSunroof(f.hasSunroof), hasNavigation(f.hasNavigation),
      hasLeatherSeats(f.hasLeatherSeats), hasBackupCamera(f.hasBackupCamera) {}
bool CarFeatures::getHasAC()           const { return hasAC; }
bool CarFeatures::getHasSunroof()      const { return hasSunroof; }
bool CarFeatures::getHasNavigation()   const { return hasNavigation; }
bool CarFeatures::getHasLeatherSeats() const { return hasLeatherSeats; }
bool CarFeatures::getHasBackupCamera() const { return hasBackupCamera; }

  
void CarFeatures::setHasAC(bool v)           { hasAC = v; }
void CarFeatures::setHasSunroof(bool v)      { hasSunroof = v; }
void CarFeatures::setHasNavigation(bool v)   { hasNavigation = v; }
void CarFeatures::setHasLeatherSeats(bool v) { hasLeatherSeats = v; }
void CarFeatures::setHasBackupCamera(bool v) { hasBackupCamera = v; }


void CarFeatures::display() const {
    cout << "  AC:"          << (hasAC          ? "Yes" : "No")
         << " | Sunroof:"    << (hasSunroof      ? "Yes" : "No")
         << " | Navigation:" << (hasNavigation   ? "Yes" : "No")
         << " | Leather:"    << (hasLeatherSeats ? "Yes" : "No")
         << " | BackupCam:"  << (hasBackupCamera ? "Yes" : "No") << "\n";
}

int CarFeatures::countFeatures() const {
    return (int)hasAC + hasSunroof + hasNavigation + hasLeatherSeats + hasBackupCamera;
}

bool CarFeatures::isPremium() const {
    return countFeatures() >= 4;
}

void CarFeatures::enableAll() {
    hasAC = hasSunroof = hasNavigation = hasLeatherSeats = hasBackupCamera = true;
}

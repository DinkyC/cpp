// #define NDEBUG // --> can set this macro to turn off debugging
#include <cassert> // for assert()
#include <cmath>   // for std::sqrt
#include <iostream>


double calculateTimeUntilObjectHitsGround(double initalHeight, double gravity) {
  assert(gravity > 0.0 && "gravity is not 0"); // The object won't reach the ground unless there is positive gravity.

  if (initalHeight <= 0.0) {
    // The object is already on the ground. Or buried.
    return 0.0;
  }
  return std::sqrt((2.0 * initalHeight) / gravity);
}

int main() {
  std::cout << "Took" << calculateTimeUntilObjectHitsGround(100.0, -9.8)
            << " seconds(s)\n";

  return 0;
}

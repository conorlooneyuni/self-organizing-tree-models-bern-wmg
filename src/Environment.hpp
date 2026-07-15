#pragma once

#include <cmath>

#include "MarkerSet.hpp"
#include "Random.hpp"
#include "Types.hpp"
#include "Config.hpp"

class Environment {
private:
  BudId nextBudId = 1;

public:
  static constexpr auto Pi = 3.1415926535897932384626433832795f;

  // In meters.
  inline static float metamerBaseLength;
  inline static float occupancyRadiusFactor;

  inline static float perceptionRadiusFactor;
  inline static float perceptionAngle;

  inline static float axillaryPerturbationAngle;

  inline static float borchertHondaAlpha;
  
  inline static float borchertHondaLambda;

  inline static float optimalGrowthDirectionWeight;

  SplitMixGenerator splitMixGenerator;
  MarkerSet markerSet;

  static void initialiseConfigValues();

  Environment(const SplitMixGenerator &SplitMixGenerator, MarkerSet markerSet);

  BudId getNextBudId();
};

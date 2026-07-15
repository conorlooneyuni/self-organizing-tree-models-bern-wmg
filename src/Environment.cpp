#include <utility>

#include "Environment.hpp"

Environment::Environment(const SplitMixGenerator &splitMixGenerator, MarkerSet markerSet)
    : splitMixGenerator(splitMixGenerator), markerSet(std::move(markerSet)) {
}

BudId Environment::getNextBudId() {
  const auto value = nextBudId;
  nextBudId++;
  return value;
}

void Environment::initialiseConfigValues() {
  // In meters.
  metamerBaseLength = std::stof(Config::getValueWithDefault("metamerBaseLength", "0.01f"));

  occupancyRadiusFactor = std::stof(Config::getValueWithDefault("occupancyRadiusFactor", "2.0f"));
  perceptionRadiusFactor = std::stof(Config::getValueWithDefault("perceptionRadiusFactor", "4.0f"));

  perceptionAngle = std::stof(Config::getValueWithDefault("perceptionAngle", "1.571f")); // Original defualt was exactly Pi / 2.0f

  axillaryPerturbationAngle = std::stof(Config::getValueWithDefault("axillaryPerturbationAngle", "0.1745f")); // Original exactly Pi / 18

  borchertHondaAlpha = std::stof(Config::getValueWithDefault("borchertHondaAlpha", "2.0f"));
  
  borchertHondaLambda = std::stof(Config::getValueWithDefault("borchertHondaLambda", "0.5f"));

  optimalGrowthDirectionWeight = std::stof(Config::getValueWithDefault("optimalGrowthDirectionWeight", "0.2f"));
}

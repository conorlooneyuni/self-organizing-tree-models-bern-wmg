#pragma once

#include "Types.hpp"

enum class UserAction : U32 { None, MoveCloser, MoveAway, MoveToBoundingBox, SteerLeft, SteerRight, SteerUp, SteerDown, Count };

inline constexpr U32 userActionToIndex(UserAction action) {
  return static_cast<U32>(action);
}

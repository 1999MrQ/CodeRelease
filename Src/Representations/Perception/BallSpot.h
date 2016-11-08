/**
 * @file BallSpot.h
 * Declaration of a struct that represents a spot that might be an indication of a ball.
 * @author <a href="mailto:Thomas.Roefer@dfki.de">Thomas Röfer</a>
 */

#pragma once

#include "Tools/Math/Eigen.h"
#include "Tools/Streams/AutoStreamable.h"

/**
 * @struct BallSpot
 * A struct that represents a spot that might be an indication of a ball.
 */
STREAMABLE(BallSpot,
{
  BallSpot() = default;
  BallSpot(Vector2i pos) : position(pos) {};
  BallSpot(int x, int y) : position(x, y) {},

  (Vector2i) position,
  (bool)(false) found,
  (bool)(false) centerFound,
  (int)(0) y,
  (int)(0) cb,
  (int)(0) cr,
  (float) radiusInImage,
});

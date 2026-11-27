// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0x7c6510 DetectionState::DetectionState
#include "DetectionState_7c6510.h"

#include <cfloat>

// Initializes a new DetectionState with default sentinel level, timestamps, and zero positions.
DetectionState::DetectionState()
    : NiRefObject(),
      level(-1000),
      hasLOS(false),
      unk15(false),
      unk16(false),
      unk18(-FLT_MAX),
      unk1C(gNiPoint3Zero),
      unk28(-FLT_MAX),
      unk2C(gNiPoint3Zero),
      unk38(-FLT_MAX),
      unk3C(gNiPoint3Zero)
{
}

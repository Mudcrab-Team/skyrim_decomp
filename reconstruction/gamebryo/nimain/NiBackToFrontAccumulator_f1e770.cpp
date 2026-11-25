// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// Adapted bodies: none
// 0xf1e770 NiBackToFrontAccumulator::NiBackToFrontAccumulator
#include "NiBackToFrontAccumulator_f1e770.h"

NiBackToFrontAccumulator::NiBackToFrontAccumulator() :
    itemsList{}, numItems(0), maxItems(0), items(nullptr), depths(nullptr), currItem(0)
{
}

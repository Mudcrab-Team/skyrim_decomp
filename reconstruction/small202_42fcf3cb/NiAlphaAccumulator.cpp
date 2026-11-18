// Origin: adapted declarations from powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0, NiAccumulator.h, NiBackToFrontAccumulator.h, NiAlphaAccumulator.h, NiTListBase.h; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Adapted declarations are licensed under GPL-3.0.
// 0xf0f210 NiAlphaAccumulator::Functionf0f210
#include "NiAlphaAccumulator.h"
void NiAlphaAccumulator::Functionf0f210(NiAlphaAccumulator* a_dest)
{
 NiBackToFrontAccumulator::CopyMembers(a_dest);
 a_dest->observeNoSortHint = observeNoSortHint;
 a_dest->sortByClosestPoint = sortByClosestPoint;
}

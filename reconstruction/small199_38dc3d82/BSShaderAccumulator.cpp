// BSShaderAccumulator, sub, Prepare, Finish: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// 0x151ee60 BSShaderAccumulator::sub

#include "BSShaderAccumulator.h"

void BSShaderAccumulator::sub(unsigned int a) { Prepare(); Finish(a); }

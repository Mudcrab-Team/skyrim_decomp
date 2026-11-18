// Origin: original reconstruction; no sibling or community implementation used.
// Source exposure: binary-analysis.
// Character, ExceedsScaledMetric, Calculate, factor: GUESS(low)
// 0x6a3290 Character::ExceedsScaledMetric
#include "Character.h"

bool Character::ExceedsScaledMetric(void* context, float threshold)
{
    const float measured = Calculate(context);
    return measured < threshold * factor;
}

// Origin: original reconstruction; no sibling or community implementation used.
// Source exposure: binary-analysis.
// Character, ExceedsScaledMetric, Calculate, factor: GUESS(low)
#pragma once
constexpr float factor = 0.5f;
class Character { public:
    float Calculate(void* context);
    bool ExceedsScaledMetric(void* context, float threshold);
};

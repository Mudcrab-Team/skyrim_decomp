// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation of the observed ground and swimming velocity modifier.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0x1066020 BhkCharacterController::ApplyInitialVelocity
#include "BhkCharacterController_1066020.h"

// zeroVelocity: GUESS(low)
alignas(16) extern const __m128 zeroVelocity;

void BhkCharacterController::ApplyInitialVelocity()
{
    const float weight = velocityTime;
    constexpr std::uint32_t chaseBip = 1u << 11;
    constexpr std::uint32_t followRagdoll = 1u << 12;
    if (weight > 0.0f) {
        if ((flags & (chaseBip | followRagdoll)) == 0) {
            // Apply one weight to all four velocity components.
            outVelocity = _mm_add_ps(_mm_mul_ps(_mm_set1_ps(weight), initialVelocity), outVelocity);
        }
    } else {
        initialVelocity = zeroVelocity;
    }
}

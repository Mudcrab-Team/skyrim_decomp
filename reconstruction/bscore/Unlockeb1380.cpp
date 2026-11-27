// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlockeb1380: GUESS(low) STANDIN; original owner is unknown
// Functioneb1380: GUESS(low); provisional entry name
// 0xeb1380 Unlockeb1380::Functioneb1380
#include "Unlockeb1380.h"

std::uint32_t Unlockeb1380::Functioneb1380()
{
    if (data)
        return (reinterpret_cast<const StringEntryeb1380*>(data) - 1)->length & 0xffffff;
    return 0;
}

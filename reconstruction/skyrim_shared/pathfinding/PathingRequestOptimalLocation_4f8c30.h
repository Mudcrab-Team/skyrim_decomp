// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// PathingRequestOptimalLocation: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function4f8c30: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// CopySource4f8c30: GUESS(low) STANDIN; polymorphic request copy interface
class PathingRequestOptimalLocation;
struct CopySource4f8c30 { virtual ~CopySource4f8c30(); virtual void Unk01(); virtual void CopyTo(PathingRequestOptimalLocation*); };

class PathingRequestOptimalLocation
{
public:

    PathingRequestOptimalLocation* Function4f8c30(CopySource4f8c30* source);
};

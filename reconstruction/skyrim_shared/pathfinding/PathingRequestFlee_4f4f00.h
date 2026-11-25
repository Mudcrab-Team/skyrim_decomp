// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// PathingRequestFlee: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function4f4f00: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// CopySource4f4f00: GUESS(low) STANDIN; polymorphic request copy interface
class PathingRequestFlee;
struct CopySource4f4f00 { virtual ~CopySource4f4f00(); virtual void Unk01(); virtual void CopyTo(PathingRequestFlee*); };

class PathingRequestFlee
{
public:

    PathingRequestFlee* Function4f4f00(CopySource4f4f00* source);
};

// Source exposure: mixed (pinned-image analysis; community and permitted sibling declarations).
// Code origin: original; handwritten from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCELL, LOADED_CELL_DATA, loadedData, portalGraph, BSPortalGraph, NiRefObject, DeleteThis, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSPortalGraph, NiRefObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only reference-counting prefix is declared.
// TESObjectCELL::Function2caf00: GUESS(low); placeholder pending name evidence.
// opaquePrefix: GUESS(low) STANDIN; unaccessed cell layout before loadedData.
#pragma once
#include <cstddef>
#include <cstdint>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long _refCount;  // volatile: shared count updated through interlocked operations.
};
static_assert(offsetof(NiRefObject, _refCount) == 0x08, "community layout");
class BSPortalGraph : public NiRefObject {};
struct LOADED_CELL_DATA
{
    BSPortalGraph* portalGraph;
};
class TESObjectCELL
{
public:
    void Function2caf00(BSPortalGraph* graph);
    std::uint8_t opaquePrefix[0x130];
    LOADED_CELL_DATA* loadedData;
};
static_assert(offsetof(TESObjectCELL, loadedData) == 0x130, "observed layout");

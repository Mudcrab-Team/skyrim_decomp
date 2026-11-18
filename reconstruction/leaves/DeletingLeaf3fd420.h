// Source exposure: binary-analysis
// DeletingLeaf3fd420, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf3fd420 {
public:
    virtual ~DeletingLeaf3fd420() {}
};
static_assert(sizeof(DeletingLeaf3fd420) == 8, "minimal virtual interface size");

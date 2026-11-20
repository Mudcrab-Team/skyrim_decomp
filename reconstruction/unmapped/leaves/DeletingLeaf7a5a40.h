// Source exposure: binary-analysis
// DeletingLeaf7a5a40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7a5a40 {
public:
    virtual ~DeletingLeaf7a5a40() {}
};
static_assert(sizeof(DeletingLeaf7a5a40) == 8, "minimal virtual interface size");

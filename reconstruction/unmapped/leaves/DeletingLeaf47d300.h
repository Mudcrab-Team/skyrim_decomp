// Source exposure: binary-analysis
// DeletingLeaf47d300, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf47d300 {
public:
    virtual ~DeletingLeaf47d300() {}
};
static_assert(sizeof(DeletingLeaf47d300) == 8, "minimal virtual interface size");

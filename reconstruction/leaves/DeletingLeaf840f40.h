// Source exposure: binary-analysis
// DeletingLeaf840f40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf840f40 {
public:
    virtual ~DeletingLeaf840f40() {}
};
static_assert(sizeof(DeletingLeaf840f40) == 8, "minimal virtual interface size");

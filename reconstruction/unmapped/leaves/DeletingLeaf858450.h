// Source exposure: binary-analysis
// DeletingLeaf858450, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf858450 {
public:
    virtual ~DeletingLeaf858450() {}
};
static_assert(sizeof(DeletingLeaf858450) == 8, "minimal virtual interface size");

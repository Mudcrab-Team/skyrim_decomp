// Source exposure: binary-analysis
// DeletingLeaf457300, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457300 {
public:
    virtual ~DeletingLeaf457300() {}
};
static_assert(sizeof(DeletingLeaf457300) == 8, "minimal virtual interface size");

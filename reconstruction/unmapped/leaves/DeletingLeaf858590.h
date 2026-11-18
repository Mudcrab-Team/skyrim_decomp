// Source exposure: binary-analysis
// DeletingLeaf858590, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf858590 {
public:
    virtual ~DeletingLeaf858590() {}
};
static_assert(sizeof(DeletingLeaf858590) == 8, "minimal virtual interface size");

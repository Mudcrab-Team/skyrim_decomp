// Source exposure: binary-analysis
// DeletingLeaf2b7590, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf2b7590 {
public:
    virtual ~DeletingLeaf2b7590() {}
};
static_assert(sizeof(DeletingLeaf2b7590) == 8, "minimal virtual interface size");

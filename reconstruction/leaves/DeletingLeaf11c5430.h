// Source exposure: binary-analysis
// DeletingLeaf11c5430, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11c5430 {
public:
    virtual ~DeletingLeaf11c5430() {}
};
static_assert(sizeof(DeletingLeaf11c5430) == 8, "minimal virtual interface size");

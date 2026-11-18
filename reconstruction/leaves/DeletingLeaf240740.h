// Source exposure: binary-analysis
// DeletingLeaf240740, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf240740 {
public:
    virtual ~DeletingLeaf240740() {}
};
static_assert(sizeof(DeletingLeaf240740) == 8, "minimal virtual interface size");

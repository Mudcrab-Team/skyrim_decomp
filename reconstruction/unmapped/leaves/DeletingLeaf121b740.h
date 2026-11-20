// Source exposure: binary-analysis
// DeletingLeaf121b740, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121b740 {
public:
    virtual ~DeletingLeaf121b740() {}
};
static_assert(sizeof(DeletingLeaf121b740) == 8, "minimal virtual interface size");

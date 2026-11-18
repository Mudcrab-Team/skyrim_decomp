// Source exposure: binary-analysis
// DeletingLeaf8a2330, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8a2330 {
public:
    virtual ~DeletingLeaf8a2330() {}
};
static_assert(sizeof(DeletingLeaf8a2330) == 8, "minimal virtual interface size");

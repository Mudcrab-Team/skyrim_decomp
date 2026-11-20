// Source exposure: binary-analysis
// DeletingLeaf1169010, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1169010 {
public:
    virtual ~DeletingLeaf1169010() {}
};
static_assert(sizeof(DeletingLeaf1169010) == 8, "minimal virtual interface size");

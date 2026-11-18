// Source exposure: binary-analysis
// DeletingLeaf832960, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832960 {
public:
    virtual ~DeletingLeaf832960() {}
};
static_assert(sizeof(DeletingLeaf832960) == 8, "minimal virtual interface size");

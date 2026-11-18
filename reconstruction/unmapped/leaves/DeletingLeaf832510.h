// Source exposure: binary-analysis
// DeletingLeaf832510, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832510 {
public:
    virtual ~DeletingLeaf832510() {}
};
static_assert(sizeof(DeletingLeaf832510) == 8, "minimal virtual interface size");

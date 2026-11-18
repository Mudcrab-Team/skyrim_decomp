// Source exposure: binary-analysis
// DeletingLeaf832380, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832380 {
public:
    virtual ~DeletingLeaf832380() {}
};
static_assert(sizeof(DeletingLeaf832380) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeaf221550, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf221550 {
public:
    virtual ~DeletingLeaf221550() {}
};
static_assert(sizeof(DeletingLeaf221550) == 8, "minimal virtual interface size");

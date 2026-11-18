// Source exposure: binary-analysis
// DeletingLeaf450030, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf450030 {
public:
    virtual ~DeletingLeaf450030() {}
};
static_assert(sizeof(DeletingLeaf450030) == 8, "minimal virtual interface size");

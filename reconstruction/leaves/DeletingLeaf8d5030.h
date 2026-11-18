// Source exposure: binary-analysis
// DeletingLeaf8d5030, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8d5030 {
public:
    virtual ~DeletingLeaf8d5030() {}
};
static_assert(sizeof(DeletingLeaf8d5030) == 8, "minimal virtual interface size");

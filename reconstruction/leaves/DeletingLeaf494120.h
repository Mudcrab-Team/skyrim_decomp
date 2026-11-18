// Source exposure: binary-analysis
// DeletingLeaf494120, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf494120 {
public:
    virtual ~DeletingLeaf494120() {}
};
static_assert(sizeof(DeletingLeaf494120) == 8, "minimal virtual interface size");

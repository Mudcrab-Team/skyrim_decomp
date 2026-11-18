// Source exposure: binary-analysis
// DeletingLeaf472490, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf472490 {
public:
    virtual ~DeletingLeaf472490() {}
};
static_assert(sizeof(DeletingLeaf472490) == 8, "minimal virtual interface size");

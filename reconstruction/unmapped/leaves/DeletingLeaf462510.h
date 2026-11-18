// Source exposure: binary-analysis
// DeletingLeaf462510, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf462510 {
public:
    virtual ~DeletingLeaf462510() {}
};
static_assert(sizeof(DeletingLeaf462510) == 8, "minimal virtual interface size");

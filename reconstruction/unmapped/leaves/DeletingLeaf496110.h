// Source exposure: binary-analysis
// DeletingLeaf496110, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf496110 {
public:
    virtual ~DeletingLeaf496110() {}
};
static_assert(sizeof(DeletingLeaf496110) == 8, "minimal virtual interface size");

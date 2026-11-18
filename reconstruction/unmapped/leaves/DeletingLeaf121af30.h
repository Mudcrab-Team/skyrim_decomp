// Source exposure: binary-analysis
// DeletingLeaf121af30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121af30 {
public:
    virtual ~DeletingLeaf121af30() {}
};
static_assert(sizeof(DeletingLeaf121af30) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeaf465180, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf465180 {
public:
    virtual ~DeletingLeaf465180() {}
};
static_assert(sizeof(DeletingLeaf465180) == 8, "minimal virtual interface size");

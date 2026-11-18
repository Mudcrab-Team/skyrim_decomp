// Source exposure: binary-analysis
// DeletingLeaf121ac90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121ac90 {
public:
    virtual ~DeletingLeaf121ac90() {}
};
static_assert(sizeof(DeletingLeaf121ac90) == 8, "minimal virtual interface size");

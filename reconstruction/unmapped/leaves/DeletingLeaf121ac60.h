// Source exposure: binary-analysis
// DeletingLeaf121ac60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121ac60 {
public:
    virtual ~DeletingLeaf121ac60() {}
};
static_assert(sizeof(DeletingLeaf121ac60) == 8, "minimal virtual interface size");

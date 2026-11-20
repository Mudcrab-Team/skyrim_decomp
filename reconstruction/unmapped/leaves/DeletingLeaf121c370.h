// Source exposure: binary-analysis
// DeletingLeaf121c370, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121c370 {
public:
    virtual ~DeletingLeaf121c370() {}
};
static_assert(sizeof(DeletingLeaf121c370) == 8, "minimal virtual interface size");

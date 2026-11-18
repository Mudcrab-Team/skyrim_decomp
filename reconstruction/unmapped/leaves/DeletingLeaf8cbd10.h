// Source exposure: binary-analysis
// DeletingLeaf8cbd10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8cbd10 {
public:
    virtual ~DeletingLeaf8cbd10() {}
};
static_assert(sizeof(DeletingLeaf8cbd10) == 8, "minimal virtual interface size");

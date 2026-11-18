// Source exposure: binary-analysis
// DeletingLeaf8cbe70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8cbe70 {
public:
    virtual ~DeletingLeaf8cbe70() {}
};
static_assert(sizeof(DeletingLeaf8cbe70) == 8, "minimal virtual interface size");

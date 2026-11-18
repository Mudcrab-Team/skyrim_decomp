// Source exposure: binary-analysis
// DeletingLeaf8bd790, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8bd790 {
public:
    virtual ~DeletingLeaf8bd790() {}
};
static_assert(sizeof(DeletingLeaf8bd790) == 8, "minimal virtual interface size");

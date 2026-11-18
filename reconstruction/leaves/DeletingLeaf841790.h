// Source exposure: binary-analysis
// DeletingLeaf841790, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf841790 {
public:
    virtual ~DeletingLeaf841790() {}
};
static_assert(sizeof(DeletingLeaf841790) == 8, "minimal virtual interface size");

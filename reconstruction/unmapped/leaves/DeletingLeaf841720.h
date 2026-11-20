// Source exposure: binary-analysis
// DeletingLeaf841720, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf841720 {
public:
    virtual ~DeletingLeaf841720() {}
};
static_assert(sizeof(DeletingLeaf841720) == 8, "minimal virtual interface size");

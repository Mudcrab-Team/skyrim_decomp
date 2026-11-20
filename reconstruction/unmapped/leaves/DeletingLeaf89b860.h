// Source exposure: binary-analysis
// DeletingLeaf89b860, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf89b860 {
public:
    virtual ~DeletingLeaf89b860() {}
};
static_assert(sizeof(DeletingLeaf89b860) == 8, "minimal virtual interface size");

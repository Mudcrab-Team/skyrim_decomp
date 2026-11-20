// Source exposure: binary-analysis
// DeletingLeaf115ca80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf115ca80 {
public:
    virtual ~DeletingLeaf115ca80() {}
};
static_assert(sizeof(DeletingLeaf115ca80) == 8, "minimal virtual interface size");

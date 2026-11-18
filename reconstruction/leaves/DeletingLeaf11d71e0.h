// Source exposure: binary-analysis
// DeletingLeaf11d71e0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11d71e0 {
public:
    virtual ~DeletingLeaf11d71e0() {}
};
static_assert(sizeof(DeletingLeaf11d71e0) == 8, "minimal virtual interface size");

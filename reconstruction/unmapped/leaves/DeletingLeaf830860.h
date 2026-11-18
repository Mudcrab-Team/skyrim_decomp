// Source exposure: binary-analysis
// DeletingLeaf830860, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830860 {
public:
    virtual ~DeletingLeaf830860() {}
};
static_assert(sizeof(DeletingLeaf830860) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeaf809ae0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809ae0 {
public:
    virtual ~DeletingLeaf809ae0() {}
};
static_assert(sizeof(DeletingLeaf809ae0) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeaf473ef0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf473ef0 {
public:
    virtual ~DeletingLeaf473ef0() {}
};
static_assert(sizeof(DeletingLeaf473ef0) == 8, "minimal virtual interface size");

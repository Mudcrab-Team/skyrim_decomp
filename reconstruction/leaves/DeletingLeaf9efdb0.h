// Source exposure: binary-analysis
// DeletingLeaf9efdb0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efdb0 {
public:
    virtual ~DeletingLeaf9efdb0() {}
};
static_assert(sizeof(DeletingLeaf9efdb0) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeaf9efae0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efae0 {
public:
    virtual ~DeletingLeaf9efae0() {}
};
static_assert(sizeof(DeletingLeaf9efae0) == 8, "minimal virtual interface size");

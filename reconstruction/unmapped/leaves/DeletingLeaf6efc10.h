// Source exposure: binary-analysis
// DeletingLeaf6efc10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf6efc10 {
public:
    virtual ~DeletingLeaf6efc10() {}
};
static_assert(sizeof(DeletingLeaf6efc10) == 8, "minimal virtual interface size");

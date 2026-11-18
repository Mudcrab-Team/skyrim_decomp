// Source exposure: binary-analysis
// DeletingLeaf78fa60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf78fa60 {
public:
    virtual ~DeletingLeaf78fa60() {}
};
static_assert(sizeof(DeletingLeaf78fa60) == 8, "minimal virtual interface size");

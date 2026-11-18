// Source exposure: binary-analysis
// DeletingLeaf846b80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf846b80 {
public:
    virtual ~DeletingLeaf846b80() {}
};
static_assert(sizeof(DeletingLeaf846b80) == 8, "minimal virtual interface size");

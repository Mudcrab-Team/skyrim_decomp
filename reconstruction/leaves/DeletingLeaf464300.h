// Source exposure: binary-analysis
// DeletingLeaf464300, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf464300 {
public:
    virtual ~DeletingLeaf464300() {}
};
static_assert(sizeof(DeletingLeaf464300) == 8, "minimal virtual interface size");

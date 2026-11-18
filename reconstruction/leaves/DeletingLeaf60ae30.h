// Source exposure: binary-analysis
// DeletingLeaf60ae30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf60ae30 {
public:
    virtual ~DeletingLeaf60ae30() {}
};
static_assert(sizeof(DeletingLeaf60ae30) == 8, "minimal virtual interface size");

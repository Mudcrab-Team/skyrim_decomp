// Source exposure: binary-analysis
// DeletingLeaf11cb800, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11cb800 {
public:
    virtual ~DeletingLeaf11cb800() {}
};
static_assert(sizeof(DeletingLeaf11cb800) == 8, "minimal virtual interface size");

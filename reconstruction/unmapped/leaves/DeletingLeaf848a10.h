// Source exposure: binary-analysis
// DeletingLeaf848a10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf848a10 {
public:
    virtual ~DeletingLeaf848a10() {}
};
static_assert(sizeof(DeletingLeaf848a10) == 8, "minimal virtual interface size");

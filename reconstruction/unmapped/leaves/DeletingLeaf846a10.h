// Source exposure: binary-analysis
// DeletingLeaf846a10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf846a10 {
public:
    virtual ~DeletingLeaf846a10() {}
};
static_assert(sizeof(DeletingLeaf846a10) == 8, "minimal virtual interface size");

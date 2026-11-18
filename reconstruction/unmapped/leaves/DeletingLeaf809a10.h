// Source exposure: binary-analysis
// DeletingLeaf809a10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809a10 {
public:
    virtual ~DeletingLeaf809a10() {}
};
static_assert(sizeof(DeletingLeaf809a10) == 8, "minimal virtual interface size");

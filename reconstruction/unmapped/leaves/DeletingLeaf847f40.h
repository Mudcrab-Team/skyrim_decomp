// Source exposure: binary-analysis
// DeletingLeaf847f40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf847f40 {
public:
    virtual ~DeletingLeaf847f40() {}
};
static_assert(sizeof(DeletingLeaf847f40) == 8, "minimal virtual interface size");

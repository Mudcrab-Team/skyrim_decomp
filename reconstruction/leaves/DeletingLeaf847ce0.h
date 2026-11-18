// Source exposure: binary-analysis
// DeletingLeaf847ce0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf847ce0 {
public:
    virtual ~DeletingLeaf847ce0() {}
};
static_assert(sizeof(DeletingLeaf847ce0) == 8, "minimal virtual interface size");

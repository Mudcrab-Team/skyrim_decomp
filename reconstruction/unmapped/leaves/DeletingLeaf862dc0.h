// Source exposure: binary-analysis
// DeletingLeaf862dc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf862dc0 {
public:
    virtual ~DeletingLeaf862dc0() {}
};
static_assert(sizeof(DeletingLeaf862dc0) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeaf121acf0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121acf0 {
public:
    virtual ~DeletingLeaf121acf0() {}
};
static_assert(sizeof(DeletingLeaf121acf0) == 8, "minimal virtual interface size");

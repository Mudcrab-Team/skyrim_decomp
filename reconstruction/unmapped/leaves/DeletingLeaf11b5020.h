// Source exposure: binary-analysis
// DeletingLeaf11b5020, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11b5020 {
public:
    virtual ~DeletingLeaf11b5020() {}
};
static_assert(sizeof(DeletingLeaf11b5020) == 8, "minimal virtual interface size");

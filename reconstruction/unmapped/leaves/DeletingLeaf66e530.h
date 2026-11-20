// Source exposure: binary-analysis
// DeletingLeaf66e530, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66e530 {
public:
    virtual ~DeletingLeaf66e530() {}
};
static_assert(sizeof(DeletingLeaf66e530) == 8, "minimal virtual interface size");

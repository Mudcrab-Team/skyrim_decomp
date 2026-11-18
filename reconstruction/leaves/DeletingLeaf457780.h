// Source exposure: binary-analysis
// DeletingLeaf457780, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457780 {
public:
    virtual ~DeletingLeaf457780() {}
};
static_assert(sizeof(DeletingLeaf457780) == 8, "minimal virtual interface size");

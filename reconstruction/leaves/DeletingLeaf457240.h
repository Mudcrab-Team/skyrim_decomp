// Source exposure: binary-analysis
// DeletingLeaf457240, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457240 {
public:
    virtual ~DeletingLeaf457240() {}
};
static_assert(sizeof(DeletingLeaf457240) == 8, "minimal virtual interface size");

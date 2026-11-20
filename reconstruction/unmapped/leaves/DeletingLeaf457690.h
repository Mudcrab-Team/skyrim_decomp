// Source exposure: binary-analysis
// DeletingLeaf457690, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457690 {
public:
    virtual ~DeletingLeaf457690() {}
};
static_assert(sizeof(DeletingLeaf457690) == 8, "minimal virtual interface size");

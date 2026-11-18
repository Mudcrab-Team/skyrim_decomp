// Source exposure: binary-analysis
// DeletingLeaf458a20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458a20 {
public:
    virtual ~DeletingLeaf458a20() {}
};
static_assert(sizeof(DeletingLeaf458a20) == 8, "minimal virtual interface size");

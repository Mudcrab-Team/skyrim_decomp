// Source exposure: binary-analysis
// DeletingLeaf80fe20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf80fe20 {
public:
    virtual ~DeletingLeaf80fe20() {}
};
static_assert(sizeof(DeletingLeaf80fe20) == 8, "minimal virtual interface size");

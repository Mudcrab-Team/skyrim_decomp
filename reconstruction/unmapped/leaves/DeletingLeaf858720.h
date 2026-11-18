// Source exposure: binary-analysis
// DeletingLeaf858720, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf858720 {
public:
    virtual ~DeletingLeaf858720() {}
};
static_assert(sizeof(DeletingLeaf858720) == 8, "minimal virtual interface size");

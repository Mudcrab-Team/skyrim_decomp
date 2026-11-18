// Source exposure: binary-analysis
// DeletingLeaf80fb00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf80fb00 {
public:
    virtual ~DeletingLeaf80fb00() {}
};
static_assert(sizeof(DeletingLeaf80fb00) == 8, "minimal virtual interface size");

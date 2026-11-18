// Source exposure: binary-analysis
// DeletingLeaf809880, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809880 {
public:
    virtual ~DeletingLeaf809880() {}
};
static_assert(sizeof(DeletingLeaf809880) == 8, "minimal virtual interface size");

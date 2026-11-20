// Source exposure: binary-analysis
// DeletingLeaf90d020, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf90d020 {
public:
    virtual ~DeletingLeaf90d020() {}
};
static_assert(sizeof(DeletingLeaf90d020) == 8, "minimal virtual interface size");

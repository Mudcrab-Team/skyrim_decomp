// Source exposure: binary-analysis
// DeletingLeaf98cdc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf98cdc0 {
public:
    virtual ~DeletingLeaf98cdc0() {}
};
static_assert(sizeof(DeletingLeaf98cdc0) == 8, "minimal virtual interface size");

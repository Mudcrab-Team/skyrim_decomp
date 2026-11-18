// Source exposure: binary-analysis
// DeletingLeafdbf140, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdbf140 {
public:
    virtual ~DeletingLeafdbf140() {}
};
static_assert(sizeof(DeletingLeafdbf140) == 8, "minimal virtual interface size");

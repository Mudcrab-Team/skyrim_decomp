// Source exposure: binary-analysis
// DeletingLeafbc97e0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbc97e0 {
public:
    virtual ~DeletingLeafbc97e0() {}
};
static_assert(sizeof(DeletingLeafbc97e0) == 8, "minimal virtual interface size");

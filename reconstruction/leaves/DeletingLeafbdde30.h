// Source exposure: binary-analysis
// DeletingLeafbdde30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbdde30 {
public:
    virtual ~DeletingLeafbdde30() {}
};
static_assert(sizeof(DeletingLeafbdde30) == 8, "minimal virtual interface size");

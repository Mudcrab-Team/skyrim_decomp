// Source exposure: binary-analysis
// DeletingLeafbeb350, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbeb350 {
public:
    virtual ~DeletingLeafbeb350() {}
};
static_assert(sizeof(DeletingLeafbeb350) == 8, "minimal virtual interface size");

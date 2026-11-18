// Source exposure: binary-analysis
// DeletingLeafbe3f50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbe3f50 {
public:
    virtual ~DeletingLeafbe3f50() {}
};
static_assert(sizeof(DeletingLeafbe3f50) == 8, "minimal virtual interface size");

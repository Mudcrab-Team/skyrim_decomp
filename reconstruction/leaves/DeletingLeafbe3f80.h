// Source exposure: binary-analysis
// DeletingLeafbe3f80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbe3f80 {
public:
    virtual ~DeletingLeafbe3f80() {}
};
static_assert(sizeof(DeletingLeafbe3f80) == 8, "minimal virtual interface size");

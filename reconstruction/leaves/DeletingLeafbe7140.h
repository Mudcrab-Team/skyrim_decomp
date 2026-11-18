// Source exposure: binary-analysis
// DeletingLeafbe7140, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbe7140 {
public:
    virtual ~DeletingLeafbe7140() {}
};
static_assert(sizeof(DeletingLeafbe7140) == 8, "minimal virtual interface size");

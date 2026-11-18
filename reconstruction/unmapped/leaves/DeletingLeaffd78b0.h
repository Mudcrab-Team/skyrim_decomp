// Source exposure: binary-analysis
// DeletingLeaffd78b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaffd78b0 {
public:
    virtual ~DeletingLeaffd78b0() {}
};
static_assert(sizeof(DeletingLeaffd78b0) == 8, "minimal virtual interface size");

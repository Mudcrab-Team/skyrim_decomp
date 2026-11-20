// Source exposure: binary-analysis
// DeletingLeafbc3c00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbc3c00 {
public:
    virtual ~DeletingLeafbc3c00() {}
};
static_assert(sizeof(DeletingLeafbc3c00) == 8, "minimal virtual interface size");

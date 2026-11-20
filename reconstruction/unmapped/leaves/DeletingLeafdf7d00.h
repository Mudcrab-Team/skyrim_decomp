// Source exposure: binary-analysis
// DeletingLeafdf7d00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdf7d00 {
public:
    virtual ~DeletingLeafdf7d00() {}
};
static_assert(sizeof(DeletingLeafdf7d00) == 8, "minimal virtual interface size");

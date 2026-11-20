// Source exposure: binary-analysis
// DeletingLeafdf7e10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdf7e10 {
public:
    virtual ~DeletingLeafdf7e10() {}
};
static_assert(sizeof(DeletingLeafdf7e10) == 8, "minimal virtual interface size");

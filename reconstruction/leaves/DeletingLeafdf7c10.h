// Source exposure: binary-analysis
// DeletingLeafdf7c10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdf7c10 {
public:
    virtual ~DeletingLeafdf7c10() {}
};
static_assert(sizeof(DeletingLeafdf7c10) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeafdf3ca0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdf3ca0 {
public:
    virtual ~DeletingLeafdf3ca0() {}
};
static_assert(sizeof(DeletingLeafdf3ca0) == 8, "minimal virtual interface size");

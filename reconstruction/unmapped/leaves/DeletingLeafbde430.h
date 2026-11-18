// Source exposure: binary-analysis
// DeletingLeafbde430, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbde430 {
public:
    virtual ~DeletingLeafbde430() {}
};
static_assert(sizeof(DeletingLeafbde430) == 8, "minimal virtual interface size");

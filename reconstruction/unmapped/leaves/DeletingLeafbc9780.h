// Source exposure: binary-analysis
// DeletingLeafbc9780, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbc9780 {
public:
    virtual ~DeletingLeafbc9780() {}
};
static_assert(sizeof(DeletingLeafbc9780) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeafbc9700, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbc9700 {
public:
    virtual ~DeletingLeafbc9700() {}
};
static_assert(sizeof(DeletingLeafbc9700) == 8, "minimal virtual interface size");

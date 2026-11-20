// Source exposure: binary-analysis
// DeletingLeafd5b150, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd5b150 {
public:
    virtual ~DeletingLeafd5b150() {}
};
static_assert(sizeof(DeletingLeafd5b150) == 8, "minimal virtual interface size");

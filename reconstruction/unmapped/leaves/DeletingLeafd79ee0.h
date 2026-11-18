// Source exposure: binary-analysis
// DeletingLeafd79ee0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd79ee0 {
public:
    virtual ~DeletingLeafd79ee0() {}
};
static_assert(sizeof(DeletingLeafd79ee0) == 8, "minimal virtual interface size");

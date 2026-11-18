// Source exposure: binary-analysis
// DeletingLeafd7d680, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd7d680 {
public:
    virtual ~DeletingLeafd7d680() {}
};
static_assert(sizeof(DeletingLeafd7d680) == 8, "minimal virtual interface size");

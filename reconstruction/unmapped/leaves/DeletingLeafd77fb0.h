// Source exposure: binary-analysis
// DeletingLeafd77fb0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd77fb0 {
public:
    virtual ~DeletingLeafd77fb0() {}
};
static_assert(sizeof(DeletingLeafd77fb0) == 8, "minimal virtual interface size");

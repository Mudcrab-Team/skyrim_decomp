// Source exposure: binary-analysis
// DeletingLeafd07690, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd07690 {
public:
    virtual ~DeletingLeafd07690() {}
};
static_assert(sizeof(DeletingLeafd07690) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeafd41550, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafd41550 {
public:
    virtual ~DeletingLeafd41550() {}
};
static_assert(sizeof(DeletingLeafd41550) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeaf458020, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458020 {
public:
    virtual ~DeletingLeaf458020() {}
};
static_assert(sizeof(DeletingLeaf458020) == 8, "minimal virtual interface size");

// Source exposure: binary-analysis
// DeletingLeaf862f20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf862f20 {
public:
    virtual ~DeletingLeaf862f20() {}
};
static_assert(sizeof(DeletingLeaf862f20) == 8, "minimal virtual interface size");

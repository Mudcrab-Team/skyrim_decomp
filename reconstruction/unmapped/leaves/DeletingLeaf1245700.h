// Source exposure: binary-analysis
// DeletingLeaf1245700, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1245700 {
public:
    virtual ~DeletingLeaf1245700() {}
};
static_assert(sizeof(DeletingLeaf1245700) == 8, "minimal virtual interface size");

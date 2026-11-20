// Source exposure: binary-analysis
// DeletingLeaf121af90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121af90 {
public:
    virtual ~DeletingLeaf121af90() {}
};
static_assert(sizeof(DeletingLeaf121af90) == 8, "minimal virtual interface size");

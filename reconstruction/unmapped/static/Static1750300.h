// Source exposure: binary-analysis; no external implementation source reused.
// Static1750300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750300*);
    virtual void release(Static1750300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750300*);
struct Static1750300 {
    void* value;
    Static1750300();
    ~Static1750300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

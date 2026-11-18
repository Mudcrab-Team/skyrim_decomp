// Source exposure: binary-analysis; no external implementation source reused.
// Static1775c40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775c40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775c40*);
    virtual void release(Static1775c40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775c40*);
struct Static1775c40 {
    void* value;
    Static1775c40();
    ~Static1775c40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

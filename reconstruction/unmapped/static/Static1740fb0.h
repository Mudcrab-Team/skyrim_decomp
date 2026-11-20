// Source exposure: binary-analysis; no external implementation source reused.
// Static1740fb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740fb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740fb0*);
    virtual void release(Static1740fb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740fb0*);
struct Static1740fb0 {
    void* value;
    Static1740fb0();
    ~Static1740fb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

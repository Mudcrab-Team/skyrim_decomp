// Source exposure: binary-analysis; no external implementation source reused.
// Static1754ea0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754ea0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754ea0*);
    virtual void release(Static1754ea0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754ea0*);
struct Static1754ea0 {
    void* value;
    Static1754ea0();
    ~Static1754ea0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

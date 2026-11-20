// Source exposure: binary-analysis; no external implementation source reused.
// Static1763db0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763db0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763db0*);
    virtual void release(Static1763db0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763db0*);
struct Static1763db0 {
    void* value;
    Static1763db0();
    ~Static1763db0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

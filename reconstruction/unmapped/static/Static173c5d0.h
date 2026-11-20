// Source exposure: binary-analysis; no external implementation source reused.
// Static173c5d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c5d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c5d0*);
    virtual void release(Static173c5d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c5d0*);
struct Static173c5d0 {
    void* value;
    Static173c5d0();
    ~Static173c5d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

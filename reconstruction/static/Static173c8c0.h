// Source exposure: binary-analysis; no external implementation source reused.
// Static173c8c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c8c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c8c0*);
    virtual void release(Static173c8c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c8c0*);
struct Static173c8c0 {
    void* value;
    Static173c8c0();
    ~Static173c8c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

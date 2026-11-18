// Source exposure: binary-analysis; no external implementation source reused.
// Static173e6e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e6e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e6e0*);
    virtual void release(Static173e6e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e6e0*);
struct Static173e6e0 {
    void* value;
    Static173e6e0();
    ~Static173e6e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

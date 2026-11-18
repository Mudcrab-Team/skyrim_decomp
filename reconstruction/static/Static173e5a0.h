// Source exposure: binary-analysis; no external implementation source reused.
// Static173e5a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e5a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e5a0*);
    virtual void release(Static173e5a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e5a0*);
struct Static173e5a0 {
    void* value;
    Static173e5a0();
    ~Static173e5a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

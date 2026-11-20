// Source exposure: binary-analysis; no external implementation source reused.
// Static173e0f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e0f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e0f0*);
    virtual void release(Static173e0f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e0f0*);
struct Static173e0f0 {
    void* value;
    Static173e0f0();
    ~Static173e0f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

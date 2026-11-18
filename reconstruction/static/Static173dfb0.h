// Source exposure: binary-analysis; no external implementation source reused.
// Static173dfb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173dfb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173dfb0*);
    virtual void release(Static173dfb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173dfb0*);
struct Static173dfb0 {
    void* value;
    Static173dfb0();
    ~Static173dfb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

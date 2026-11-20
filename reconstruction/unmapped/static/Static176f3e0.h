// Source exposure: binary-analysis; no external implementation source reused.
// Static176f3e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f3e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f3e0*);
    virtual void release(Static176f3e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f3e0*);
struct Static176f3e0 {
    void* value;
    Static176f3e0();
    ~Static176f3e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

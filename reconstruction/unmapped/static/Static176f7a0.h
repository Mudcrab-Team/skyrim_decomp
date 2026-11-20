// Source exposure: binary-analysis; no external implementation source reused.
// Static176f7a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f7a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f7a0*);
    virtual void release(Static176f7a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f7a0*);
struct Static176f7a0 {
    void* value;
    Static176f7a0();
    ~Static176f7a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

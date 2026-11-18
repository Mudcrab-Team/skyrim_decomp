// Source exposure: binary-analysis; no external implementation source reused.
// Static177beb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177beb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177beb0*);
    virtual void release(Static177beb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177beb0*);
struct Static177beb0 {
    void* value;
    Static177beb0();
    ~Static177beb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

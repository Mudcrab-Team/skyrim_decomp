// Source exposure: binary-analysis; no external implementation source reused.
// Static177b5f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b5f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b5f0*);
    virtual void release(Static177b5f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b5f0*);
struct Static177b5f0 {
    void* value;
    Static177b5f0();
    ~Static177b5f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

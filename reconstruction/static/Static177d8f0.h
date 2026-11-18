// Source exposure: binary-analysis; no external implementation source reused.
// Static177d8f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d8f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d8f0*);
    virtual void release(Static177d8f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d8f0*);
struct Static177d8f0 {
    void* value;
    Static177d8f0();
    ~Static177d8f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

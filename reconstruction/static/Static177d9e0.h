// Source exposure: binary-analysis; no external implementation source reused.
// Static177d9e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d9e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d9e0*);
    virtual void release(Static177d9e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d9e0*);
struct Static177d9e0 {
    void* value;
    Static177d9e0();
    ~Static177d9e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

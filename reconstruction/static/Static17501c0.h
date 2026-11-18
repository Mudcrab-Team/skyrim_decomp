// Source exposure: binary-analysis; no external implementation source reused.
// Static17501c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17501c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17501c0*);
    virtual void release(Static17501c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17501c0*);
struct Static17501c0 {
    void* value;
    Static17501c0();
    ~Static17501c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

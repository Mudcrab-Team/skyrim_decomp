// Source exposure: binary-analysis; no external implementation source reused.
// Static177fec0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fec0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fec0*);
    virtual void release(Static177fec0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fec0*);
struct Static177fec0 {
    void* value;
    Static177fec0();
    ~Static177fec0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

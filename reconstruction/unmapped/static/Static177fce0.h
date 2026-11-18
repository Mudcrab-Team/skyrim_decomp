// Source exposure: binary-analysis; no external implementation source reused.
// Static177fce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fce0*);
    virtual void release(Static177fce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fce0*);
struct Static177fce0 {
    void* value;
    Static177fce0();
    ~Static177fce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

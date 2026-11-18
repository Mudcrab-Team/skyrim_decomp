// Source exposure: binary-analysis; no external implementation source reused.
// Static177aba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177aba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177aba0*);
    virtual void release(Static177aba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177aba0*);
struct Static177aba0 {
    void* value;
    Static177aba0();
    ~Static177aba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

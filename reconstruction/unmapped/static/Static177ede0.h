// Source exposure: binary-analysis; no external implementation source reused.
// Static177ede0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ede0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ede0*);
    virtual void release(Static177ede0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ede0*);
struct Static177ede0 {
    void* value;
    Static177ede0();
    ~Static177ede0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

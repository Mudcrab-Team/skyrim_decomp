// Source exposure: binary-analysis; no external implementation source reused.
// Static177cfe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cfe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cfe0*);
    virtual void release(Static177cfe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cfe0*);
struct Static177cfe0 {
    void* value;
    Static177cfe0();
    ~Static177cfe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

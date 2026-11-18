// Source exposure: binary-analysis; no external implementation source reused.
// Static177df30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177df30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177df30*);
    virtual void release(Static177df30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177df30*);
struct Static177df30 {
    void* value;
    Static177df30();
    ~Static177df30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

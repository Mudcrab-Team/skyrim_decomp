// Source exposure: binary-analysis; no external implementation source reused.
// Static177a6a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a6a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a6a0*);
    virtual void release(Static177a6a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a6a0*);
struct Static177a6a0 {
    void* value;
    Static177a6a0();
    ~Static177a6a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

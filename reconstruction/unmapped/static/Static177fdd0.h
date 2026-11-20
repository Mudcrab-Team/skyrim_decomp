// Source exposure: binary-analysis; no external implementation source reused.
// Static177fdd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fdd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fdd0*);
    virtual void release(Static177fdd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fdd0*);
struct Static177fdd0 {
    void* value;
    Static177fdd0();
    ~Static177fdd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

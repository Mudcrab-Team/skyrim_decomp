// Source exposure: binary-analysis; no external implementation source reused.
// Static177dda0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177dda0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177dda0*);
    virtual void release(Static177dda0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177dda0*);
struct Static177dda0 {
    void* value;
    Static177dda0();
    ~Static177dda0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

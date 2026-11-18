// Source exposure: binary-analysis; no external implementation source reused.
// Static177ddf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ddf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ddf0*);
    virtual void release(Static177ddf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ddf0*);
struct Static177ddf0 {
    void* value;
    Static177ddf0();
    ~Static177ddf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

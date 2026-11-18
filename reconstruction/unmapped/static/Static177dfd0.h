// Source exposure: binary-analysis; no external implementation source reused.
// Static177dfd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177dfd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177dfd0*);
    virtual void release(Static177dfd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177dfd0*);
struct Static177dfd0 {
    void* value;
    Static177dfd0();
    ~Static177dfd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

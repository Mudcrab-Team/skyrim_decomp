// Source exposure: binary-analysis; no external implementation source reused.
// Static177abf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177abf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177abf0*);
    virtual void release(Static177abf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177abf0*);
struct Static177abf0 {
    void* value;
    Static177abf0();
    ~Static177abf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

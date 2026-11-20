// Source exposure: binary-analysis; no external implementation source reused.
// Static177f4c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f4c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f4c0*);
    virtual void release(Static177f4c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f4c0*);
struct Static177f4c0 {
    void* value;
    Static177f4c0();
    ~Static177f4c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

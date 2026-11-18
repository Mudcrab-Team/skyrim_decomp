// Source exposure: binary-analysis; no external implementation source reused.
// Static177ac90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ac90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ac90*);
    virtual void release(Static177ac90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ac90*);
struct Static177ac90 {
    void* value;
    Static177ac90();
    ~Static177ac90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

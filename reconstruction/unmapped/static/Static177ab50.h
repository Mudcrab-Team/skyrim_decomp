// Source exposure: binary-analysis; no external implementation source reused.
// Static177ab50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ab50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ab50*);
    virtual void release(Static177ab50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ab50*);
struct Static177ab50 {
    void* value;
    Static177ab50();
    ~Static177ab50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

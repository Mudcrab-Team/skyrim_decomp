// Source exposure: binary-analysis; no external implementation source reused.
// Static177cf40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cf40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cf40*);
    virtual void release(Static177cf40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cf40*);
struct Static177cf40 {
    void* value;
    Static177cf40();
    ~Static177cf40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

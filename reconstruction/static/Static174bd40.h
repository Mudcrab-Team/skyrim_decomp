// Source exposure: binary-analysis; no external implementation source reused.
// Static174bd40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bd40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bd40*);
    virtual void release(Static174bd40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bd40*);
struct Static174bd40 {
    void* value;
    Static174bd40();
    ~Static174bd40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

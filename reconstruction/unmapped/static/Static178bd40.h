// Source exposure: binary-analysis; no external implementation source reused.
// Static178bd40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178bd40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178bd40*);
    virtual void release(Static178bd40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178bd40*);
struct Static178bd40 {
    void* value;
    Static178bd40();
    ~Static178bd40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

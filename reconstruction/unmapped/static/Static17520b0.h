// Source exposure: binary-analysis; no external implementation source reused.
// Static17520b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17520b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17520b0*);
    virtual void release(Static17520b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17520b0*);
struct Static17520b0 {
    void* value;
    Static17520b0();
    ~Static17520b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

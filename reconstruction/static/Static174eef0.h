// Source exposure: binary-analysis; no external implementation source reused.
// Static174eef0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174eef0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174eef0*);
    virtual void release(Static174eef0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174eef0*);
struct Static174eef0 {
    void* value;
    Static174eef0();
    ~Static174eef0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

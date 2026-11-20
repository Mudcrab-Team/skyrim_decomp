// Source exposure: binary-analysis; no external implementation source reused.
// Static174fef0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fef0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fef0*);
    virtual void release(Static174fef0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fef0*);
struct Static174fef0 {
    void* value;
    Static174fef0();
    ~Static174fef0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

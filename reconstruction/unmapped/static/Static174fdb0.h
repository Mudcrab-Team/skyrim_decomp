// Source exposure: binary-analysis; no external implementation source reused.
// Static174fdb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fdb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fdb0*);
    virtual void release(Static174fdb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fdb0*);
struct Static174fdb0 {
    void* value;
    Static174fdb0();
    ~Static174fdb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

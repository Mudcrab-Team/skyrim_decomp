// Source exposure: binary-analysis; no external implementation source reused.
// Static176df90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176df90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176df90*);
    virtual void release(Static176df90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176df90*);
struct Static176df90 {
    void* value;
    Static176df90();
    ~Static176df90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

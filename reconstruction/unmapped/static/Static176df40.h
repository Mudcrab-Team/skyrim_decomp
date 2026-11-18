// Source exposure: binary-analysis; no external implementation source reused.
// Static176df40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176df40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176df40*);
    virtual void release(Static176df40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176df40*);
struct Static176df40 {
    void* value;
    Static176df40();
    ~Static176df40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

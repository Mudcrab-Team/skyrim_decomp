// Source exposure: binary-analysis; no external implementation source reused.
// Static17779f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17779f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17779f0*);
    virtual void release(Static17779f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17779f0*);
struct Static17779f0 {
    void* value;
    Static17779f0();
    ~Static17779f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

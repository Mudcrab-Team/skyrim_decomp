// Source exposure: binary-analysis; no external implementation source reused.
// Static179dff0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179dff0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179dff0*);
    virtual void release(Static179dff0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179dff0*);
struct Static179dff0 {
    void* value;
    Static179dff0();
    ~Static179dff0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

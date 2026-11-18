// Source exposure: binary-analysis; no external implementation source reused.
// Static179e4d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e4d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e4d0*);
    virtual void release(Static179e4d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e4d0*);
struct Static179e4d0 {
    void* value;
    Static179e4d0();
    ~Static179e4d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

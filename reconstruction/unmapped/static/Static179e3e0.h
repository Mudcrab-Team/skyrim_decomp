// Source exposure: binary-analysis; no external implementation source reused.
// Static179e3e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e3e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e3e0*);
    virtual void release(Static179e3e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e3e0*);
struct Static179e3e0 {
    void* value;
    Static179e3e0();
    ~Static179e3e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

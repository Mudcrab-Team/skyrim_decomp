// Source exposure: binary-analysis; no external implementation source reused.
// Static179ecc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ecc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ecc0*);
    virtual void release(Static179ecc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ecc0*);
struct Static179ecc0 {
    void* value;
    Static179ecc0();
    ~Static179ecc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

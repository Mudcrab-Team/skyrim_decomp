// Source exposure: binary-analysis; no external implementation source reused.
// Static179a3a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179a3a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179a3a0*);
    virtual void release(Static179a3a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179a3a0*);
struct Static179a3a0 {
    void* value;
    Static179a3a0();
    ~Static179a3a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

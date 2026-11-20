// Source exposure: binary-analysis; no external implementation source reused.
// Static179c6b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c6b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c6b0*);
    virtual void release(Static179c6b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c6b0*);
struct Static179c6b0 {
    void* value;
    Static179c6b0();
    ~Static179c6b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

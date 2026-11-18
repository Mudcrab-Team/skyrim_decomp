// Source exposure: binary-analysis; no external implementation source reused.
// Static17aeca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aeca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aeca0*);
    virtual void release(Static17aeca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aeca0*);
struct Static17aeca0 {
    void* value;
    Static17aeca0();
    ~Static17aeca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

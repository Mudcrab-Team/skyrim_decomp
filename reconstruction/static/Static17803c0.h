// Source exposure: binary-analysis; no external implementation source reused.
// Static17803c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17803c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17803c0*);
    virtual void release(Static17803c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17803c0*);
struct Static17803c0 {
    void* value;
    Static17803c0();
    ~Static17803c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

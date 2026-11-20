// Source exposure: binary-analysis; no external implementation source reused.
// Static17c0e00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c0e00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c0e00*);
    virtual void release(Static17c0e00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c0e00*);
struct Static17c0e00 {
    void* value;
    Static17c0e00();
    ~Static17c0e00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

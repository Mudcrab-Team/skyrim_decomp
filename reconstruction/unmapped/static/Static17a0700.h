// Source exposure: binary-analysis; no external implementation source reused.
// Static17a0700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a0700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a0700*);
    virtual void release(Static17a0700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a0700*);
struct Static17a0700 {
    void* value;
    Static17a0700();
    ~Static17a0700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

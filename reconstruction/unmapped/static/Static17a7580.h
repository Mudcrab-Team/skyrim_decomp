// Source exposure: binary-analysis; no external implementation source reused.
// Static17a7580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a7580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a7580*);
    virtual void release(Static17a7580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a7580*);
struct Static17a7580 {
    void* value;
    Static17a7580();
    ~Static17a7580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

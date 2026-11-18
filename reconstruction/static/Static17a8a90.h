// Source exposure: binary-analysis; no external implementation source reused.
// Static17a8a90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a8a90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a8a90*);
    virtual void release(Static17a8a90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a8a90*);
struct Static17a8a90 {
    void* value;
    Static17a8a90();
    ~Static17a8a90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static17a8a40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a8a40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a8a40*);
    virtual void release(Static17a8a40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a8a40*);
struct Static17a8a40 {
    void* value;
    Static17a8a40();
    ~Static17a8a40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

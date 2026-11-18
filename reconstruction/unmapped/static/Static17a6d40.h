// Source exposure: binary-analysis; no external implementation source reused.
// Static17a6d40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a6d40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a6d40*);
    virtual void release(Static17a6d40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a6d40*);
struct Static17a6d40 {
    void* value;
    Static17a6d40();
    ~Static17a6d40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static17a5a40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a5a40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a5a40*);
    virtual void release(Static17a5a40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a5a40*);
struct Static17a5a40 {
    void* value;
    Static17a5a40();
    ~Static17a5a40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

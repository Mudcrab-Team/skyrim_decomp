// Source exposure: binary-analysis; no external implementation source reused.
// Static17a0d80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a0d80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a0d80*);
    virtual void release(Static17a0d80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a0d80*);
struct Static17a0d80 {
    void* value;
    Static17a0d80();
    ~Static17a0d80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

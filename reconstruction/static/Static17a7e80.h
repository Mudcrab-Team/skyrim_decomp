// Source exposure: binary-analysis; no external implementation source reused.
// Static17a7e80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a7e80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a7e80*);
    virtual void release(Static17a7e80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a7e80*);
struct Static17a7e80 {
    void* value;
    Static17a7e80();
    ~Static17a7e80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

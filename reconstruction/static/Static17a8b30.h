// Source exposure: binary-analysis; no external implementation source reused.
// Static17a8b30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a8b30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a8b30*);
    virtual void release(Static17a8b30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a8b30*);
struct Static17a8b30 {
    void* value;
    Static17a8b30();
    ~Static17a8b30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

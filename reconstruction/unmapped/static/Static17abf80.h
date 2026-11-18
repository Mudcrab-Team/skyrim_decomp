// Source exposure: binary-analysis; no external implementation source reused.
// Static17abf80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17abf80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17abf80*);
    virtual void release(Static17abf80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17abf80*);
struct Static17abf80 {
    void* value;
    Static17abf80();
    ~Static17abf80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

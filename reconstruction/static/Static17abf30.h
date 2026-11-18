// Source exposure: binary-analysis; no external implementation source reused.
// Static17abf30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17abf30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17abf30*);
    virtual void release(Static17abf30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17abf30*);
struct Static17abf30 {
    void* value;
    Static17abf30();
    ~Static17abf30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

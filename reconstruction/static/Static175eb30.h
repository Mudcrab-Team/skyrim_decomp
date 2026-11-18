// Source exposure: binary-analysis; no external implementation source reused.
// Static175eb30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175eb30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175eb30*);
    virtual void release(Static175eb30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175eb30*);
struct Static175eb30 {
    void* value;
    Static175eb30();
    ~Static175eb30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

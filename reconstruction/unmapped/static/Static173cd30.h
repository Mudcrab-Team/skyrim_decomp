// Source exposure: binary-analysis; no external implementation source reused.
// Static173cd30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cd30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cd30*);
    virtual void release(Static173cd30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cd30*);
struct Static173cd30 {
    void* value;
    Static173cd30();
    ~Static173cd30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

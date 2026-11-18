// Source exposure: binary-analysis; no external implementation source reused.
// Static174cd30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174cd30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174cd30*);
    virtual void release(Static174cd30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174cd30*);
struct Static174cd30 {
    void* value;
    Static174cd30();
    ~Static174cd30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

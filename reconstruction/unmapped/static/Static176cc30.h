// Source exposure: binary-analysis; no external implementation source reused.
// Static176cc30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cc30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cc30*);
    virtual void release(Static176cc30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cc30*);
struct Static176cc30 {
    void* value;
    Static176cc30();
    ~Static176cc30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

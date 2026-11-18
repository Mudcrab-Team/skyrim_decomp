// Source exposure: binary-analysis; no external implementation source reused.
// Static176da40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176da40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176da40*);
    virtual void release(Static176da40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176da40*);
struct Static176da40 {
    void* value;
    Static176da40();
    ~Static176da40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

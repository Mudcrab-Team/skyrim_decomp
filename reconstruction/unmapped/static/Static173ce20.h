// Source exposure: binary-analysis; no external implementation source reused.
// Static173ce20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ce20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ce20*);
    virtual void release(Static173ce20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ce20*);
struct Static173ce20 {
    void* value;
    Static173ce20();
    ~Static173ce20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

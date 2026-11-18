// Source exposure: binary-analysis; no external implementation source reused.
// Static176af20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176af20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176af20*);
    virtual void release(Static176af20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176af20*);
struct Static176af20 {
    void* value;
    Static176af20();
    ~Static176af20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

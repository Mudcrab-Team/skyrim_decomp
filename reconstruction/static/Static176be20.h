// Source exposure: binary-analysis; no external implementation source reused.
// Static176be20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176be20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176be20*);
    virtual void release(Static176be20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176be20*);
struct Static176be20 {
    void* value;
    Static176be20();
    ~Static176be20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

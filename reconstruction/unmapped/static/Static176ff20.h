// Source exposure: binary-analysis; no external implementation source reused.
// Static176ff20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ff20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ff20*);
    virtual void release(Static176ff20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ff20*);
struct Static176ff20 {
    void* value;
    Static176ff20();
    ~Static176ff20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

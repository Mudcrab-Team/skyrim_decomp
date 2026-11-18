// Source exposure: binary-analysis; no external implementation source reused.
// Static176fa70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fa70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fa70*);
    virtual void release(Static176fa70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fa70*);
struct Static176fa70 {
    void* value;
    Static176fa70();
    ~Static176fa70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static173fa70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173fa70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173fa70*);
    virtual void release(Static173fa70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173fa70*);
struct Static173fa70 {
    void* value;
    Static173fa70();
    ~Static173fa70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

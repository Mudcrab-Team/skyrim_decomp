// Source exposure: binary-analysis; no external implementation source reused.
// Static176af70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176af70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176af70*);
    virtual void release(Static176af70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176af70*);
struct Static176af70 {
    void* value;
    Static176af70();
    ~Static176af70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

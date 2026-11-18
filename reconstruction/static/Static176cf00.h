// Source exposure: binary-analysis; no external implementation source reused.
// Static176cf00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cf00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cf00*);
    virtual void release(Static176cf00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cf00*);
struct Static176cf00 {
    void* value;
    Static176cf00();
    ~Static176cf00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

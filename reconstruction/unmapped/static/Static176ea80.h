// Source exposure: binary-analysis; no external implementation source reused.
// Static176ea80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ea80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ea80*);
    virtual void release(Static176ea80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ea80*);
struct Static176ea80 {
    void* value;
    Static176ea80();
    ~Static176ea80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

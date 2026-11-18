// Source exposure: binary-analysis; no external implementation source reused.
// Static176ea30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ea30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ea30*);
    virtual void release(Static176ea30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ea30*);
struct Static176ea30 {
    void* value;
    Static176ea30();
    ~Static176ea30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static173cfc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cfc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cfc0*);
    virtual void release(Static173cfc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cfc0*);
struct Static173cfc0 {
    void* value;
    Static173cfc0();
    ~Static173cfc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

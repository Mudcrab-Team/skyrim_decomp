// Source exposure: binary-analysis; no external implementation source reused.
// Static173cce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cce0*);
    virtual void release(Static173cce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cce0*);
struct Static173cce0 {
    void* value;
    Static173cce0();
    ~Static173cce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

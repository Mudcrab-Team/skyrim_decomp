// Source exposure: binary-analysis; no external implementation source reused.
// Static173cec0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cec0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cec0*);
    virtual void release(Static173cec0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cec0*);
struct Static173cec0 {
    void* value;
    Static173cec0();
    ~Static173cec0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

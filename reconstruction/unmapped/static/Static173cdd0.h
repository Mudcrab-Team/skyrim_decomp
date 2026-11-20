// Source exposure: binary-analysis; no external implementation source reused.
// Static173cdd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cdd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cdd0*);
    virtual void release(Static173cdd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cdd0*);
struct Static173cdd0 {
    void* value;
    Static173cdd0();
    ~Static173cdd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

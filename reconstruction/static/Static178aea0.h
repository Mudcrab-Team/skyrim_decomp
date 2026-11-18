// Source exposure: binary-analysis; no external implementation source reused.
// Static178aea0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178aea0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178aea0*);
    virtual void release(Static178aea0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178aea0*);
struct Static178aea0 {
    void* value;
    Static178aea0();
    ~Static178aea0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

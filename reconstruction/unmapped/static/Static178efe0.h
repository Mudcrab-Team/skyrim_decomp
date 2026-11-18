// Source exposure: binary-analysis; no external implementation source reused.
// Static178efe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178efe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178efe0*);
    virtual void release(Static178efe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178efe0*);
struct Static178efe0 {
    void* value;
    Static178efe0();
    ~Static178efe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

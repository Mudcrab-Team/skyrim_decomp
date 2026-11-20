// Source exposure: binary-analysis; no external implementation source reused.
// Static178fba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178fba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178fba0*);
    virtual void release(Static178fba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178fba0*);
struct Static178fba0 {
    void* value;
    Static178fba0();
    ~Static178fba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

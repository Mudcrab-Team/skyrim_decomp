// Source exposure: binary-analysis; no external implementation source reused.
// Static178cba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cba0*);
    virtual void release(Static178cba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cba0*);
struct Static178cba0 {
    void* value;
    Static178cba0();
    ~Static178cba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static175ecc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ecc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ecc0*);
    virtual void release(Static175ecc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ecc0*);
struct Static175ecc0 {
    void* value;
    Static175ecc0();
    ~Static175ecc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

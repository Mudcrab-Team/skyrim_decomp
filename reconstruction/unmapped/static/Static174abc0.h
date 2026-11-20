// Source exposure: binary-analysis; no external implementation source reused.
// Static174abc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174abc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174abc0*);
    virtual void release(Static174abc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174abc0*);
struct Static174abc0 {
    void* value;
    Static174abc0();
    ~Static174abc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

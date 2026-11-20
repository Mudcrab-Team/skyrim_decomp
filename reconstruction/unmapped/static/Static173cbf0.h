// Source exposure: binary-analysis; no external implementation source reused.
// Static173cbf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cbf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cbf0*);
    virtual void release(Static173cbf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cbf0*);
struct Static173cbf0 {
    void* value;
    Static173cbf0();
    ~Static173cbf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

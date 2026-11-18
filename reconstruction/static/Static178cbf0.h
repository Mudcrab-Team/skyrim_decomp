// Source exposure: binary-analysis; no external implementation source reused.
// Static178cbf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cbf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cbf0*);
    virtual void release(Static178cbf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cbf0*);
struct Static178cbf0 {
    void* value;
    Static178cbf0();
    ~Static178cbf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

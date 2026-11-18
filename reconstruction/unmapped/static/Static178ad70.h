// Source exposure: binary-analysis; no external implementation source reused.
// Static178ad70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ad70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ad70*);
    virtual void release(Static178ad70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ad70*);
struct Static178ad70 {
    void* value;
    Static178ad70();
    ~Static178ad70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

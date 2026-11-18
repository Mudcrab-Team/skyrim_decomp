// Source exposure: binary-analysis; no external implementation source reused.
// Static173eba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173eba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173eba0*);
    virtual void release(Static173eba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173eba0*);
struct Static173eba0 {
    void* value;
    Static173eba0();
    ~Static173eba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

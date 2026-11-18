// Source exposure: binary-analysis; no external implementation source reused.
// Static173edd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173edd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173edd0*);
    virtual void release(Static173edd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173edd0*);
struct Static173edd0 {
    void* value;
    Static173edd0();
    ~Static173edd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

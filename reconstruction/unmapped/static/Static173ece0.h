// Source exposure: binary-analysis; no external implementation source reused.
// Static173ece0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ece0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ece0*);
    virtual void release(Static173ece0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ece0*);
struct Static173ece0 {
    void* value;
    Static173ece0();
    ~Static173ece0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

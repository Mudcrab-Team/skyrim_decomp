// Source exposure: binary-analysis; no external implementation source reused.
// Static178a7c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a7c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a7c0*);
    virtual void release(Static178a7c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a7c0*);
struct Static178a7c0 {
    void* value;
    Static178a7c0();
    ~Static178a7c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

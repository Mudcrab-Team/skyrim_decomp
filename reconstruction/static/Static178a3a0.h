// Source exposure: binary-analysis; no external implementation source reused.
// Static178a3a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a3a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a3a0*);
    virtual void release(Static178a3a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a3a0*);
struct Static178a3a0 {
    void* value;
    Static178a3a0();
    ~Static178a3a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static178eea0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178eea0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178eea0*);
    virtual void release(Static178eea0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178eea0*);
struct Static178eea0 {
    void* value;
    Static178eea0();
    ~Static178eea0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

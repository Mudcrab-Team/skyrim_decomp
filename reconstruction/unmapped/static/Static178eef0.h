// Source exposure: binary-analysis; no external implementation source reused.
// Static178eef0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178eef0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178eef0*);
    virtual void release(Static178eef0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178eef0*);
struct Static178eef0 {
    void* value;
    Static178eef0();
    ~Static178eef0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

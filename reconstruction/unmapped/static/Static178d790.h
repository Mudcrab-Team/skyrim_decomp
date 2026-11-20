// Source exposure: binary-analysis; no external implementation source reused.
// Static178d790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d790*);
    virtual void release(Static178d790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d790*);
struct Static178d790 {
    void* value;
    Static178d790();
    ~Static178d790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

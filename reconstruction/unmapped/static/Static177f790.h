// Source exposure: binary-analysis; no external implementation source reused.
// Static177f790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f790*);
    virtual void release(Static177f790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f790*);
struct Static177f790 {
    void* value;
    Static177f790();
    ~Static177f790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

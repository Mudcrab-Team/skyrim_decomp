// Source exposure: binary-analysis; no external implementation source reused.
// Static176f520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f520*);
    virtual void release(Static176f520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f520*);
struct Static176f520 {
    void* value;
    Static176f520();
    ~Static176f520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

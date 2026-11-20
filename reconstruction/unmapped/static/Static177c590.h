// Source exposure: binary-analysis; no external implementation source reused.
// Static177c590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c590*);
    virtual void release(Static177c590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c590*);
struct Static177c590 {
    void* value;
    Static177c590();
    ~Static177c590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

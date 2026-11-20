// Source exposure: binary-analysis; no external implementation source reused.
// Static176d590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d590*);
    virtual void release(Static176d590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d590*);
struct Static176d590 {
    void* value;
    Static176d590();
    ~Static176d590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

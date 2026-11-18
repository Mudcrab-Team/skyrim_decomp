// Source exposure: binary-analysis; no external implementation source reused.
// Static176cf50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cf50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cf50*);
    virtual void release(Static176cf50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cf50*);
struct Static176cf50 {
    void* value;
    Static176cf50();
    ~Static176cf50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

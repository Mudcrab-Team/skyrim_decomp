// Source exposure: binary-analysis; no external implementation source reused.
// Static176bc90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bc90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bc90*);
    virtual void release(Static176bc90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bc90*);
struct Static176bc90 {
    void* value;
    Static176bc90();
    ~Static176bc90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

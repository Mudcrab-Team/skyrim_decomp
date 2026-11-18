// Source exposure: binary-analysis; no external implementation source reused.
// Static17654d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17654d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17654d0*);
    virtual void release(Static17654d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17654d0*);
struct Static17654d0 {
    void* value;
    Static17654d0();
    ~Static17654d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

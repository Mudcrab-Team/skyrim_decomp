// Source exposure: binary-analysis; no external implementation source reused.
// Static176ccd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ccd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ccd0*);
    virtual void release(Static176ccd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ccd0*);
struct Static176ccd0 {
    void* value;
    Static176ccd0();
    ~Static176ccd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

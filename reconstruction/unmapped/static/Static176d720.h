// Source exposure: binary-analysis; no external implementation source reused.
// Static176d720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d720*);
    virtual void release(Static176d720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d720*);
struct Static176d720 {
    void* value;
    Static176d720();
    ~Static176d720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

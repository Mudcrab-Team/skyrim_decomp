// Source exposure: binary-analysis; no external implementation source reused.
// Static176ac50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ac50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ac50*);
    virtual void release(Static176ac50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ac50*);
struct Static176ac50 {
    void* value;
    Static176ac50();
    ~Static176ac50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static176ad40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ad40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ad40*);
    virtual void release(Static176ad40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ad40*);
struct Static176ad40 {
    void* value;
    Static176ad40();
    ~Static176ad40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

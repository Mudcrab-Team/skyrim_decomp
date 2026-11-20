// Source exposure: binary-analysis; no external implementation source reused.
// Static176dc20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176dc20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176dc20*);
    virtual void release(Static176dc20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176dc20*);
struct Static176dc20 {
    void* value;
    Static176dc20();
    ~Static176dc20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

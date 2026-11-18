// Source exposure: binary-analysis; no external implementation source reused.
// Static176dc70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176dc70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176dc70*);
    virtual void release(Static176dc70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176dc70*);
struct Static176dc70 {
    void* value;
    Static176dc70();
    ~Static176dc70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static176ba10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ba10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ba10*);
    virtual void release(Static176ba10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ba10*);
struct Static176ba10 {
    void* value;
    Static176ba10();
    ~Static176ba10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

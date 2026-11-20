// Source exposure: binary-analysis; no external implementation source reused.
// Static176cfa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cfa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cfa0*);
    virtual void release(Static176cfa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cfa0*);
struct Static176cfa0 {
    void* value;
    Static176cfa0();
    ~Static176cfa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

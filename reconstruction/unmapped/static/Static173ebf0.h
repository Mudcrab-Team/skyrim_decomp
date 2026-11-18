// Source exposure: binary-analysis; no external implementation source reused.
// Static173ebf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ebf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ebf0*);
    virtual void release(Static173ebf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ebf0*);
struct Static173ebf0 {
    void* value;
    Static173ebf0();
    ~Static173ebf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

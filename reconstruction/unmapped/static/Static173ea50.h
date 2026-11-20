// Source exposure: binary-analysis; no external implementation source reused.
// Static173ea50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ea50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ea50*);
    virtual void release(Static173ea50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ea50*);
struct Static173ea50 {
    void* value;
    Static173ea50();
    ~Static173ea50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

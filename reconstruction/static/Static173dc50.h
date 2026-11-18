// Source exposure: binary-analysis; no external implementation source reused.
// Static173dc50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173dc50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173dc50*);
    virtual void release(Static173dc50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173dc50*);
struct Static173dc50 {
    void* value;
    Static173dc50();
    ~Static173dc50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

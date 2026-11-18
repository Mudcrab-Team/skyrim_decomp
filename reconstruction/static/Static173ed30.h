// Source exposure: binary-analysis; no external implementation source reused.
// Static173ed30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ed30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ed30*);
    virtual void release(Static173ed30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ed30*);
struct Static173ed30 {
    void* value;
    Static173ed30();
    ~Static173ed30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

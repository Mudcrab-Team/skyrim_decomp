// Source exposure: binary-analysis; no external implementation source reused.
// Static173da60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173da60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173da60*);
    virtual void release(Static173da60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173da60*);
struct Static173da60 {
    void* value;
    Static173da60();
    ~Static173da60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

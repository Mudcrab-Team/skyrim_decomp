// Source exposure: binary-analysis; no external implementation source reused.
// Static173da10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173da10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173da10*);
    virtual void release(Static173da10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173da10*);
struct Static173da10 {
    void* value;
    Static173da10();
    ~Static173da10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

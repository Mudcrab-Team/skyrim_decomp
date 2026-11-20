// Source exposure: binary-analysis; no external implementation source reused.
// Static176ad90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ad90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ad90*);
    virtual void release(Static176ad90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ad90*);
struct Static176ad90 {
    void* value;
    Static176ad90();
    ~Static176ad90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

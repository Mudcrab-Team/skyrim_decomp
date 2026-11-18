// Source exposure: binary-analysis; no external implementation source reused.
// Static174f630, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f630;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f630*);
    virtual void release(Static174f630*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f630*);
struct Static174f630 {
    void* value;
    Static174f630();
    ~Static174f630() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

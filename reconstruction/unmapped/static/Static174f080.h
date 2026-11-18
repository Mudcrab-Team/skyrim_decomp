// Source exposure: binary-analysis; no external implementation source reused.
// Static174f080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f080*);
    virtual void release(Static174f080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f080*);
struct Static174f080 {
    void* value;
    Static174f080();
    ~Static174f080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static174d760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d760*);
    virtual void release(Static174d760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d760*);
struct Static174d760 {
    void* value;
    Static174d760();
    ~Static174d760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

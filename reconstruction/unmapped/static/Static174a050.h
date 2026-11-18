// Source exposure: binary-analysis; no external implementation source reused.
// Static174a050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174a050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174a050*);
    virtual void release(Static174a050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174a050*);
struct Static174a050 {
    void* value;
    Static174a050();
    ~Static174a050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

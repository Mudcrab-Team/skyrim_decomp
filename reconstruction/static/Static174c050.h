// Source exposure: binary-analysis; no external implementation source reused.
// Static174c050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174c050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174c050*);
    virtual void release(Static174c050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174c050*);
struct Static174c050 {
    void* value;
    Static174c050();
    ~Static174c050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

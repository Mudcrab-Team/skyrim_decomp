// Source exposure: binary-analysis; no external implementation source reused.
// Static174f400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f400*);
    virtual void release(Static174f400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f400*);
struct Static174f400 {
    void* value;
    Static174f400();
    ~Static174f400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

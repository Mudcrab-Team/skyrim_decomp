// Source exposure: binary-analysis; no external implementation source reused.
// Static174f450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f450*);
    virtual void release(Static174f450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f450*);
struct Static174f450 {
    void* value;
    Static174f450();
    ~Static174f450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

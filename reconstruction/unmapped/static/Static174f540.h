// Source exposure: binary-analysis; no external implementation source reused.
// Static174f540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f540*);
    virtual void release(Static174f540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f540*);
struct Static174f540 {
    void* value;
    Static174f540();
    ~Static174f540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

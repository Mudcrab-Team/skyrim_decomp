// Source exposure: binary-analysis; no external implementation source reused.
// Static178f910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f910*);
    virtual void release(Static178f910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f910*);
struct Static178f910 {
    void* value;
    Static178f910();
    ~Static178f910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

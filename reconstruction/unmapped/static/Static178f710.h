// Source exposure: binary-analysis; no external implementation source reused.
// Static178f710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f710*);
    virtual void release(Static178f710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f710*);
struct Static178f710 {
    void* value;
    Static178f710();
    ~Static178f710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

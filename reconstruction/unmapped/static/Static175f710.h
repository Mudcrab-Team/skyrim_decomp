// Source exposure: binary-analysis; no external implementation source reused.
// Static175f710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f710*);
    virtual void release(Static175f710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f710*);
struct Static175f710 {
    void* value;
    Static175f710();
    ~Static175f710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

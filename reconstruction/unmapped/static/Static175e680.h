// Source exposure: binary-analysis; no external implementation source reused.
// Static175e680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e680*);
    virtual void release(Static175e680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e680*);
struct Static175e680 {
    void* value;
    Static175e680();
    ~Static175e680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

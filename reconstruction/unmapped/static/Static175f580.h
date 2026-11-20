// Source exposure: binary-analysis; no external implementation source reused.
// Static175f580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f580*);
    virtual void release(Static175f580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f580*);
struct Static175f580 {
    void* value;
    Static175f580();
    ~Static175f580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

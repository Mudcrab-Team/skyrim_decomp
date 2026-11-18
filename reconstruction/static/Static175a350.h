// Source exposure: binary-analysis; no external implementation source reused.
// Static175a350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a350*);
    virtual void release(Static175a350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a350*);
struct Static175a350 {
    void* value;
    Static175a350();
    ~Static175a350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

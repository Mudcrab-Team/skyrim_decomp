// Source exposure: binary-analysis; no external implementation source reused.
// Static175daf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175daf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175daf0*);
    virtual void release(Static175daf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175daf0*);
struct Static175daf0 {
    void* value;
    Static175daf0();
    ~Static175daf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

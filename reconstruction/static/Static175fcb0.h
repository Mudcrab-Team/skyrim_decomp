// Source exposure: binary-analysis; no external implementation source reused.
// Static175fcb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fcb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fcb0*);
    virtual void release(Static175fcb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fcb0*);
struct Static175fcb0 {
    void* value;
    Static175fcb0();
    ~Static175fcb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static175cdd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cdd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cdd0*);
    virtual void release(Static175cdd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cdd0*);
struct Static175cdd0 {
    void* value;
    Static175cdd0();
    ~Static175cdd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

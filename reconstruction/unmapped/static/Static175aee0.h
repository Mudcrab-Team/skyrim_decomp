// Source exposure: binary-analysis; no external implementation source reused.
// Static175aee0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175aee0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175aee0*);
    virtual void release(Static175aee0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175aee0*);
struct Static175aee0 {
    void* value;
    Static175aee0();
    ~Static175aee0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

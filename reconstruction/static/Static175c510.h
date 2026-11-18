// Source exposure: binary-analysis; no external implementation source reused.
// Static175c510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c510*);
    virtual void release(Static175c510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c510*);
struct Static175c510 {
    void* value;
    Static175c510();
    ~Static175c510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static175f170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f170*);
    virtual void release(Static175f170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f170*);
struct Static175f170 {
    void* value;
    Static175f170();
    ~Static175f170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

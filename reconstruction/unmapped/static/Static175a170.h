// Source exposure: binary-analysis; no external implementation source reused.
// Static175a170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a170*);
    virtual void release(Static175a170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a170*);
struct Static175a170 {
    void* value;
    Static175a170();
    ~Static175a170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

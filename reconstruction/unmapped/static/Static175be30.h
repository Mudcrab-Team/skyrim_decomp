// Source exposure: binary-analysis; no external implementation source reused.
// Static175be30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175be30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175be30*);
    virtual void release(Static175be30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175be30*);
struct Static175be30 {
    void* value;
    Static175be30();
    ~Static175be30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

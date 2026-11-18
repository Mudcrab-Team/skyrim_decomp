// Source exposure: binary-analysis; no external implementation source reused.
// Static175cd30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cd30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cd30*);
    virtual void release(Static175cd30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cd30*);
struct Static175cd30 {
    void* value;
    Static175cd30();
    ~Static175cd30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static175e630, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e630;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e630*);
    virtual void release(Static175e630*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e630*);
struct Static175e630 {
    void* value;
    Static175e630();
    ~Static175e630() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

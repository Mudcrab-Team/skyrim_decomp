// Source exposure: binary-analysis; no external implementation source reused.
// Static175e770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e770*);
    virtual void release(Static175e770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e770*);
struct Static175e770 {
    void* value;
    Static175e770();
    ~Static175e770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

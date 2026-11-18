// Source exposure: binary-analysis; no external implementation source reused.
// Static175e540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e540*);
    virtual void release(Static175e540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e540*);
struct Static175e540 {
    void* value;
    Static175e540();
    ~Static175e540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

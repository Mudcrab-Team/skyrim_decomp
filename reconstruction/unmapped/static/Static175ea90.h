// Source exposure: binary-analysis; no external implementation source reused.
// Static175ea90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ea90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ea90*);
    virtual void release(Static175ea90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ea90*);
struct Static175ea90 {
    void* value;
    Static175ea90();
    ~Static175ea90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

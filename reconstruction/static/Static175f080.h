// Source exposure: binary-analysis; no external implementation source reused.
// Static175f080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f080*);
    virtual void release(Static175f080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f080*);
struct Static175f080 {
    void* value;
    Static175f080();
    ~Static175f080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

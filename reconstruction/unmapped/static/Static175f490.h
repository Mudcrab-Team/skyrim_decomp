// Source exposure: binary-analysis; no external implementation source reused.
// Static175f490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f490*);
    virtual void release(Static175f490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f490*);
struct Static175f490 {
    void* value;
    Static175f490();
    ~Static175f490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

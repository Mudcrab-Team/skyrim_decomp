// Source exposure: binary-analysis; no external implementation source reused.
// Static175f990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f990*);
    virtual void release(Static175f990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f990*);
struct Static175f990 {
    void* value;
    Static175f990();
    ~Static175f990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

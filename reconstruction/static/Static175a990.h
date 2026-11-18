// Source exposure: binary-analysis; no external implementation source reused.
// Static175a990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a990*);
    virtual void release(Static175a990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a990*);
struct Static175a990 {
    void* value;
    Static175a990();
    ~Static175a990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static175a940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a940*);
    virtual void release(Static175a940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a940*);
struct Static175a940 {
    void* value;
    Static175a940();
    ~Static175a940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

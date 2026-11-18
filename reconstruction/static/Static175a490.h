// Source exposure: binary-analysis; no external implementation source reused.
// Static175a490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a490*);
    virtual void release(Static175a490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a490*);
struct Static175a490 {
    void* value;
    Static175a490();
    ~Static175a490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

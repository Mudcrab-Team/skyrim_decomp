// Source exposure: binary-analysis; no external implementation source reused.
// Static175a300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a300*);
    virtual void release(Static175a300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a300*);
struct Static175a300 {
    void* value;
    Static175a300();
    ~Static175a300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static175a850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a850*);
    virtual void release(Static175a850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a850*);
struct Static175a850 {
    void* value;
    Static175a850();
    ~Static175a850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};

// Source exposure: binary-analysis; no external implementation source reused.
// Static175af30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175af30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175af30*);
    virtual void release(Static175af30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175af30*);
struct Static175af30 {
    void* value;
    Static175af30();
    ~Static175af30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
